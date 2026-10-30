#include <iostream>
#include <fstream>

using namespace std;

class FileViewer
{
public:
    virtual ~FileViewer() {}

    virtual void Display(const char *path)
    {
        ifstream file(path);
        if (!file.is_open())
        {
            cout << "Cannot open file: " << path << endl;
            return;
        }

        char ch;
        while (file.get(ch))
            cout << ch;
        cout << endl;
    }
};

class AsciiViewer : public FileViewer
{
public:
    void Display(const char *path) override
    {
        ifstream file(path, ios::binary);
        if (!file.is_open())
        {
            cout << "Cannot open file: " << path << endl;
            return;
        }

        char ch;
        while (file.get(ch))
            cout << static_cast<int>(static_cast<unsigned char>(ch)) << ' ';
        cout << endl;
    }
};

class BinaryViewer : public FileViewer
{
public:
    void Display(const char *path) override
    {
        ifstream file(path, ios::binary);
        if (!file.is_open())
        {
            cout << "Cannot open file: " << path << endl;
            return;
        }

        char ch;
        while (file.get(ch))
        {
            unsigned char value = static_cast<unsigned char>(ch);
            for (int bit = 7; bit >= 0; --bit)
                cout << ((value >> bit) & 1);
            cout << ' ';
        }
        cout << endl;
    }
};

class HexViewer : public FileViewer
{
public:
    void Display(const char *path) override
    {
        ifstream file(path, ios::binary);
        if (!file.is_open())
        {
            cout << "Cannot open file: " << path << endl;
            return;
        }

        const char digits[] = "0123456789ABCDEF";
        char ch;
        while (file.get(ch))
        {
            unsigned char value = static_cast<unsigned char>(ch);
            cout << digits[value >> 4] << digits[value & 15] << ' ';
        }
        cout << endl;
    }
};

int main()
{
    const char *path = "test.txt";

    {
        ofstream out(path);
        out << "Hello, C++!\n";
    }

    FileViewer *viewers[] = {
        new FileViewer(),
        new AsciiViewer(),
        new BinaryViewer(),
        new HexViewer()};
    const char *names[] = {"Text", "ASCII codes", "Binary", "Hexadecimal"};

    for (int i = 0; i < 4; ++i)
    {
        cout << "=== " << names[i] << " ===" << endl;
        viewers[i]->Display(path);
        cout << endl;
    }

    for (FileViewer *v : viewers)
        delete v;

    return 0;
}