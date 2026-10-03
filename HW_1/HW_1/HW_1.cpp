#include <iostream>
#include <Windows.h>
using namespace std;

int getLength(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char* task1(char* str, int index) {
    int len = getLength(str);
    if (index >= 0 && index < len) {
        for (int i = index; i < len; i++) {
            str[i] = str[i + 1];
        }
    }
    return str;
}

char* task2(char* str, char ch) {
    int readIndex = 0;
    int writeIndex = 0;

    while (str[readIndex] != '\0') {
        if (str[readIndex] != ch) {
            str[writeIndex] = str[readIndex];
            writeIndex++;
        }
        readIndex++;
    }
    str[writeIndex] = '\0';
    return str;
}

char* task3(char* str, int index, char ch) {
    int len = getLength(str);
    if (index >= 0 && index <= len) {
        for (int i = len; i >= index; i--) {
            str[i + 1] = str[i];
        }
        str[index] = ch;
    }
    return str;
}

void task4() {
    char input[256];
    cin.getline(input, 256);

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '.') {
            input[i] = '!';
        }
    }
    cout << input << "\n";
}

void task5() {
    char input[256];
    char target;

    cin.getline(input, 256);
    cin >> target;
    cin.ignore();

    int count = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == target) {
            count++;
        }
    }
    cout << count << "\n";
}

void task6() {
    char input[256];
    cin.getline(input, 256);

    int letters = 0;
    int digits = 0;
    int others = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        if (ch >= 48 && ch <= 57) {
            digits++;
        }
        else if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
            letters++;
        }
        else {
            others++;
        }
    }

    cout << letters << "\n";
    cout << digits << "\n";
    cout << others << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char str1[100] = "Hello World";
    char str2[100] = "abracadabra";
    char str3[100] = "Hello";

    task6();

    return 0;
}