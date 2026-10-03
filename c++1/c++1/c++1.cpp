#include <iostream>
#include <Windows.h>

using namespace std;

int mystrlen(const char* str) {
	int index = 0;
	while (str[index] != '\0') {
		index++;
	}
	return index;
}
char* mystrcpy(char* str1, char* str2) {
	int sizeOfstr2 = mystrlen(str2);
	str1 = new char[sizeOfstr2 + 1];
	for (int i = 0; i < sizeOfstr2; i++) {
		str1[i] = str2[i];
	}
	str1[sizeOfstr2] = '\0';
	return  str1;
}


char* mystrcat(char* str1, const char* str2) {
	int len1 = mystrlen(str1);
	int len2 = mystrlen(str2);
	char* str3 = new char[len1 + len2];
	for (int i = 0; i < len1; i++) {
		str3[i] = str1[i];
	}
	for (int i = 0; i < len2; i++) {
		str3[i + len1] = str2[i];
	}
	delete[] str1;
	str1 = new char[len1 + len2 + 1];
	for (int i = 0; i < len1 + len2; i++) {
		str1[i] = str3[i];
	}

	str1[len1 + len2] = '\0';
	delete[] str3;
	return str1;
}

char* mystrchr(char* str, char s) {
	char* start = str;
	while (*start != '\0' || *start != s) {
		start++;
	}
	if (*start == '\0') {
		return nullptr;
	}
}



char* mystrstr(char* str1, char* str2) {
	char* start = str1;
	int str1_lenght = mystrlen(str1);
	int str2_lenght = mystrlen(str2);
	int counter = 0;
	while (*start != '\0') {
		if (counter + str2_lenght > str1_lenght) {
			return counter;
		}
		for (int i = 0; i < str2_lenght; i++) {
			if (*(start + i) != str2[i]) {
				break;
			}
			if (i == str2_lenght - 1) {
				return start;
			}
		}
		start++;
		counter++;
	}
}










int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	char str[200];
	cout << "Введіть текст";
	cin >> str;
	char* str1 = nullptr;
	str1 = mystrcpy(str1, str);
	cin >> str;
	char* str2 = nullptr;
	//str2 = mystrcpy(str2, str);
	//cout << "Довжина тексту: " << mystrlen(str) << endl;
	//cout << "Змінений текст: " << str1 << endl;

	//str1 = mystrcat(str1, str2);
	//cout << "Обєднаний текст" << str1 << endl;

	char lol;
	cin >> lol;
	char* a = mystrchr(str1, lol);
	if (a != nullptr) {
		cout << *a;
	}
	else {
		cout << "Такого не існує ";
	}
	return 0;
}
