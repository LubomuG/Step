#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool IsWordChar(char c)
{
    unsigned char u = static_cast<unsigned char>(c);
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || u >= 128;
}

char ToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return static_cast<char>(c - 'A' + 'a');
    return c;
}

bool BuildDictionary(const string &path, map<string, int> &dictionary, int &totalWords)
{
    ifstream file(path.c_str());
    if (!file.is_open())
        return false;

    totalWords = 0;
    string line;
    string word;

    while (getline(file, line))
    {
        for (size_t i = 0; i <= line.size(); ++i)
        {
            if (i < line.size() && IsWordChar(line[i]))
            {
                word += ToLower(line[i]);
            }
            else if (!word.empty())
            {
                ++dictionary[word];
                ++totalWords;
                word.clear();
            }
        }
    }
    return true;
}

bool CompareEntries(const pair<string, int> &a, const pair<string, int> &b)
{
    if (a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

vector<pair<string, int>> SortByFrequency(const map<string, int> &dictionary)
{
    vector<pair<string, int>> entries(dictionary.begin(), dictionary.end());
    sort(entries.begin(), entries.end(), CompareEntries);
    return entries;
}

void PrintAllWords(ostream &out, const vector<pair<string, int>> &entries, int totalWords)
{
    out << "Total words: " << totalWords << endl;
    out << "Unique words: " << entries.size() << endl;
    out << endl
        << "Word frequencies:" << endl;
    for (size_t i = 0; i < entries.size(); ++i)
        out << entries[i].first << " : " << entries[i].second << endl;
}

void PrintMostFrequent(ostream &out, const vector<pair<string, int>> &entries)
{
    out << endl
        << "Most frequent word";
    if (entries.empty())
    {
        out << ": none" << endl;
        return;
    }

    int maxCount = entries[0].second;
    size_t ties = 0;
    while (ties < entries.size() && entries[ties].second == maxCount)
        ++ties;

    if (ties > 1)
        out << "s";
    out << " (" << maxCount << " times):" << endl;
    for (size_t i = 0; i < ties; ++i)
        out << entries[i].first << endl;
}

void PrintReport(ostream &out, const vector<pair<string, int>> &entries, int totalWords)
{
    PrintAllWords(out, entries, totalWords);
    PrintMostFrequent(out, entries);
}

int main()
{
    string inputPath;
    string outputPath;

    cout << "Input file: ";
    getline(cin, inputPath);
    cout << "Output file: ";
    getline(cin, outputPath);

    map<string, int> dictionary;
    int totalWords = 0;

    if (!BuildDictionary(inputPath, dictionary, totalWords))
    {
        cout << "Cannot open file: " << inputPath << endl;
        return 1;
    }

    vector<pair<string, int>> entries = SortByFrequency(dictionary);

    cout << endl;
    PrintReport(cout, entries, totalWords);

    ofstream out(outputPath.c_str());
    if (!out.is_open())
    {
        cout << endl
             << "Cannot open file for writing: " << outputPath << endl;
        return 1;
    }
    PrintReport(out, entries, totalWords);
    cout << endl
         << "Result saved to " << outputPath << endl;

    return 0;
}