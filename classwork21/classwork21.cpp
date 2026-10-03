#include <iostream>
#include "Class.h"
#include <fstream>
#include <random>
#include <ctime>
#include <cmath>

using namespace std;

int rowsCount = 0;

int string_to_int(char* string, int size) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        result += (string[i] - '0') * pow(10, size - i - 1);
    }
    return result;
}

char** LoadFromFile(const char* filePath) {
    ifstream fin(filePath);

    if (!fin.is_open()) {
        cout << "File not opened";
        return nullptr;
    }

    char buffer[250];
    rowsCount = 0;

    while (fin.getline(buffer, 250)) {
        rowsCount++;
    }

    fin.clear();
    fin.seekg(0, ios::beg);

    char** arr = new char* [rowsCount];

    for (int i = 0; i < rowsCount; i++) {
        arr[i] = new char[250];
        fin.getline(arr[i], 250);
    }

    fin.close();
    return arr;
}

int wordLen(char* word) {
    int i = 0;
    while (word[i] != '\0') {
        i++;
    }
    return i;
}

int wordCount(char* row) {
    int count = 1;
    int i = 0;

    while (row[i] != '\0') {
        if (row[i] == ' ') {
            count++;
        }
        i++;
    }

    return count;
}

char* reversRow(char* row) {

    int count = wordCount(row);

    char** words = new char* [count];
    int* wordLens = new int[count];

    for (int i = 0; i < count; i++) {
        wordLens[i] = 0;
    }

    int i = 0;
    int currentWord = 0;

    while (row[i] != '\0') {
        if (row[i] != ' ') {
            wordLens[currentWord]++;
        }
        else {
            currentWord++;
        }
        i++;
    }

    for (int i = 0; i < count; i++) {
        words[i] = new char[wordLens[i] + 1];
    }

    int currentIndex = 0;

    for (int i = 0; i < count; i++) {

        int currentSize = 0;

        while (row[currentIndex] != ' ' &&
            row[currentIndex] != '\0') {

            words[i][currentSize] = row[currentIndex];
            currentSize++;
            currentIndex++;
        }

        words[i][currentSize] = '\0';
        currentIndex++;
    }

    for (int i = 0; i < count; i++) {

        for (int j = 0; j < wordLens[i] / 2; j++) {

            char temp = words[i][j];
            words[i][j] = words[i][wordLens[i] - j - 1];
            words[i][wordLens[i] - j - 1] = temp;
        }
    }

    char* result = new char[wordLen(row) + 1];

    int pos = 0;

    for (int i = 0; i < count; i++) {

        for (int j = 0; j < wordLens[i]; j++) {
            result[pos++] = words[i][j];
        }

        if (i != count - 1) {
            result[pos++] = ' ';
        }
    }

    result[pos] = '\0';

    return result;
}

int main()
{
    srand(4541);

    /*ifstream fin("C:\\Users\\lubom\\Desktop\\IT\\Step\\C++\\github folder\\classwork21\\student.txt");
if (!fin.is_open()) {
    cout << "Something went wrong and we couldnt open the file" << endl;
    return 1;
}


int  size = 0;
char buffer[50];
fin >> buffer;
size = string_to_int(buffer, 2);



Class myGroup{
    "p56", 15, new Student[size]
};

for (int i = 0; i < myGroup.studentCount; i++) {
    fin >> myGroup.arr[i].surname;
    fin >> myGroup.arr[i].name;
    fin >> buffer;
    myGroup.arr[i].grade = string_to_int(buffer, 2);
}
int good_students = 0;
int bad_students = 0;
for (int i = 0; i < myGroup.studentCount; i++) {
    if (myGroup.arr[i].grade > 50) {
        good_students++;
    }
    else {
        bad_students++;
    }
}
ofstream Good("C:\\Users\\lubom\\Desktop\\IT\\Step\\C++\\github folder\\classwork21\\goodStudent.txt");
Good << good_students << endl;
ofstream Bad("C:\\Users\\lubom\Desktop\\IT\\Step\\C++\\github folder\\classwork21\\badStudent.txt");
Bad << bad_students << endl;
for (int i = 0; i < myGroup.studentCount; i++) {
    if (myGroup.arr[i].grade > 50) {
        Good << myGroup.arr[i].surname << " ";
        Good << myGroup.arr[i].name << " ";
        Good << myGroup.arr[i].grade << " " << endl;
    }
    else {
        Bad << myGroup.arr[i].surname << " ";
        Bad << myGroup.arr[i].name << " ";
        Bad << myGroup.arr[i].grade << " " << endl;
    }
}
Good.close();
fin.close();
Bad.close();*/
    /*int rows;
int colums;
cout << "Enter rows";
cin >> rows;
cout << "enter colums";
cin >> colums;

int** dunamicmatr;
dunamicmatr = new int* [rows];
for (int i = 0; i < rows; ++i) {
    dunamicmatr[i] = new int[colums];
    for (int j = 0; j < colums; ++j) {

    }
}

int rowstoChange;
int columstoChange;
cout << "Enter rows to change";
cin >> rowstoChange;
cout << "enter colums to change";
cin >> columstoChange;

if (rowstoChange < rows && columstoChange < colums) {
    dunamicmatr[rowstoChange][columstoChange] = 5;
}
else {
    cout << "Invalid Input";
}



for (int i = 0; i < rows;++i) {
    for (int j = 0;j < colums;++j) {
        cout << dunamicmatr[i][j] << " ";
    }
    cout << endl;
}*/
    /*char** arr;
char row[255] = "Hello world  i love C++\0";
int wordcount = 5;
arr = new char* [wordcount];
int currentIndex = 0;
int currentSize = 0;

for (int i = 0; i < wordcount; ++i) {
    while (row[currentIndex] != " " && row[currentIndex] != '\0') {
        currentIndex++;
        currentSize;
    }
    arr[i] = new char[currentSize];
    currentSize = 0;
    currentIndex++;
}
currentIndex = 0;
currentSize = 0;
for (int i = 0; i < wordcount; ++i) {
    while (row[currentIndex] != " " && row[currentIndex] != '\0') {
        arr[i][currentSize] = row[currentIndex];
        currentSize++;
        currentIndex++;

    }
    arr[i][currentSize] = '\0';
    currentSize = 0;
    currentIndex++;

}


for (int i = 0; i < wordcount; ++i) {
    cout << arr[i] << endl;
}*/
    /* int x;
int y;
cout << "Enter rows";
cin >> x;
cout << "enter colums";
cin >> y;

int** arr;
arr = new int* [x];
for (int i = 0; i < x; ++i) {
    arr[i] = new int[y];
}



for (int i = 0; i < x;++i) {
    for (int j = 0;j < y;++j) {
        arr[i][j] = rand() % 100;
        cout << arr[i][j] << ", ";
    }
    cout << endl;
}





int** arr2;
arr2 = new int* [x + 1];


for (int i = 0; i < x + 1; ++i) {
    arr[i] = new int[y];
}



for (int i = 0; i < x + 1;++i) {
    if (i ==x) {
        for (int j = 0; j < y; ++j) {
            cout << "enter number";
            cin >> arr2[i][j];
        }
    }
    else {
        for (int j = 0;j < y;++j) {
            arr2[i][j] = arr[i][j];
        }
    }

}

for (int i = 0; i < x; i++) {
    delete arr[i];
}
delete[] arr;

arr = arr2;

for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
        cout << arr[i][j];
    }
}
*/
    /*
int rows1, colums1;
int rows2, colums2;
cout << "Enter rows for matrix one";
cin >> rows1;
cout << "ENter colums for matrix one";
cin >> colums1;
int** matr1 = new int* [rows1];

for (int i = 0;i < rows1; i++) {
    matr1[i] = new int[colums1];
    for (int j = 0;j < colums1; j++) {
        matr1[i][j] = rand() % 10;
    }
}

cout << "Enter rows for matrix two";
cin >> rows2;
cout << "ENter colums for matrix two";
cin >> colums2;

int** matr2 = new int* [rows2];

for (int i = 0;i < rows2; i++) {
    matr2[i] = new int[colums2];
    for (int j = 0;j < colums2; j++) {
        matr2[i][j] = rand() % 10;
    }
}

int max_row, max_col;
max_row = rows1 > rows2 ? rows1 : rows2;
max_col = colums1 > colums2 ? colums1 : colums2;
int** matr3 = new int* [max_row];

for (int i = 0;i < max_row; i++) {
    matr3[i] = new int[max_col];
    for (int j = 0;j < max_col; j++) {
        if (i > rows1 - 1) {
            if (j < colums2) {
                matr3[i][j] = 0 + matr2[i][j];
            }
            else {
                matr3[i][j] = 0 + 0;
            }
        }
        else {
            if (j < rows2) {
                if (j < colums1) {
                    matr3[i][j] = matr1[i][j] + 0;
                }
                else {
                    matr3[i][j] = 0 + 0;
                }
            }
            else {
                if (j < colums1 && j < colums2) {
                    matr3[i][j] = matr1[i][j] + matr2[i][j];
                }
                else {
                    if (j > colums1 - 1) {
                        if (j > colums2 - 1) {
                            matr3[i][j] = 0 + 0;
                        }
                        else {
                            matr3[i][j] = 0 + matr2[i][j];
                        }
                    }
                    else {
                        if (j > colums1 - 1) {
                            matr3[i][j] = 0 + 0;
                        }
                        else {
                            matr3[i][j] = 0 + matr2[i][j];
                        }
                    }
                }
            }
        }
    }
}

cout << "Result matrix:" << endl;
for (int i = 0;i < max_row; i++) {
    for (int j = 0;j < max_col; j++) {
        cout << matr3[i][j] << " ";
    }
    cout << endl;
}

for (int i = 0;i < rows1; i++) {
    delete[] matr1[i];
}
delete[] matr1;

for (int i = 0;i < rows2; i++) {
    delete[] matr2[i];
}
delete[] matr2;

for (int i = 0;i < max_row; i++) {
    delete[] matr3[i];
}
delete[] matr3;
*/

       // hw

    char** rows = LoadFromFile("C:\\Users\\lubom\\Desktop\\IT\\Step\\C++\\github folder\\classwork21\\hiiiiiiii.txt");

    if (rows == nullptr) {
        return 1;
    }

    ofstream fout("C:\\Users\\lubom\\Desktop\\IT\\Step\\C++\\github folder\\classwork21\\hiiiiiiii.txt");

    for (int i = 0; i < rowsCount; i++) {

        char* newRow = reversRow(rows[i]);

        fout << newRow << endl;

        delete[] newRow;
    }

    fout.close();

    for (int i = 0; i < rowsCount; i++) {
        delete[] rows[i];
    }
    delete[] rows;

    cout << "Done!" << endl;

    return 0;
}