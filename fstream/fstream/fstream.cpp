#include <iostream>
#include <fstream>
#include "windows.h"

using namespace std;

const int MAX_NAME_LEN = 50;
const int MAX_EMPLOYEES = 100;
const int MAX_BUFFER = 256;

struct Employee {
    char lastName[MAX_NAME_LEN];
    char firstName[MAX_NAME_LEN];
    int age;
    double salary;
};

class EmployeeSystem {
private:
    Employee employees[MAX_EMPLOYEES];
    int employeeCount;
    char dataFileName[MAX_BUFFER];

    int stringLength(const char* str) {
        int len = 0;
        while (str[len] != '\0') {
            len++;
        }
        return len;
    }

    void stringCopy(char* dest, const char* src) {
        int i = 0;
        while (src[i] != '\0' && i < MAX_NAME_LEN - 1) {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    int stringCompare(const char* str1, const char* str2) {
        int i = 0;
        while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
            i++;
        }
        return str1[i] - str2[i];
    }

    void trim(char* str) {
        int start = 0;
        int end = stringLength(str) - 1;

        while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n') {
            start++;
        }

        if (start > 0) {
            int i = 0;
            while (str[start + i] != '\0') {
                str[i] = str[start + i];
                i++;
            }
            str[i] = '\0';
        }

        end = stringLength(str) - 1;
        while (end >= 0 && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')) {
            str[end] = '\0';
            end--;
        }
    }

    char toUpperCase(char ch) {
        if (ch >= 'a' && ch <= 'z') {
            return ch - 'a' + 'A';
        }
        return ch;
    }

    bool compareLastNames(const char* a, const char* b) {
        return stringCompare(a, b) == 0;
    }

    bool startsWithLetter(const char* str, char letter) {
        if (str[0] == '\0') return false;
        char upperLetter = toUpperCase(letter);
        char firstChar = toUpperCase(str[0]);
        return firstChar == upperLetter;
    }

    int stringToInt(const char* str) {
        int result = 0;
        int i = 0;
        while (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
            i++;
        }
        return result;
    }

    double stringToDouble(const char* str) {
        double result = 0.0;
        double fraction = 0.0;
        int i = 0;
        int sign = 1;

        if (str[i] == '-') {
            sign = -1;
            i++;
        }

        while (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
            i++;
        }

        if (str[i] == '.') {
            i++;
            double divisor = 1.0;
            while (str[i] >= '0' && str[i] <= '9') {
                fraction = fraction * 10 + (str[i] - '0');
                divisor *= 10;
                i++;
            }
            result += fraction / divisor;
        }

        return result * sign;
    }

public:
    EmployeeSystem() : employeeCount(0) {
        stringCopy(dataFileName, "C:\\Users\\lubom\\Desktop\\IT\\Step\\C++\\github folder\\fstream\\fstream\\sdf.txt");
    }

    void loadFromFile() {
        ifstream fin(dataFileName);

        if (fin.is_open()) {
            employeeCount = 0;
            char buffer[MAX_BUFFER];

            while (fin.getline(buffer, MAX_BUFFER) && employeeCount < MAX_EMPLOYEES) {
                char lastName[MAX_NAME_LEN] = "";
                char firstName[MAX_NAME_LEN] = "";
                char ageStr[10] = "";
                char salaryStr[20] = "";

                int field = 0;
                int pos = 0;
                int i = 0;

                while (buffer[i] != '\0' && field < 4) {
                    if (buffer[i] == '|') {
                        field++;
                        pos = 0;
                        i++;
                        continue;
                    }

                    if (field == 0 && pos < MAX_NAME_LEN - 1) {
                        lastName[pos++] = buffer[i];
                        lastName[pos] = '\0';
                    }
                    else if (field == 1 && pos < MAX_NAME_LEN - 1) {
                        firstName[pos++] = buffer[i];
                        firstName[pos] = '\0';
                    }
                    else if (field == 2 && pos < 9) {
                        ageStr[pos++] = buffer[i];
                        ageStr[pos] = '\0';
                    }
                    else if (field == 3 && pos < 19) {
                        salaryStr[pos++] = buffer[i];
                        salaryStr[pos] = '\0';
                    }
                    i++;
                }

                if (stringLength(lastName) > 0) {
                    stringCopy(employees[employeeCount].lastName, lastName);
                    stringCopy(employees[employeeCount].firstName, firstName);
                    employees[employeeCount].age = stringToInt(ageStr);
                    employees[employeeCount].salary = stringToDouble(salaryStr);
                    employeeCount++;
                }
            }

            fin.close();
            cout << "Loaded " << employeeCount << " employees from file." << endl;
        }
        else {
            cout << "File not found! Path: " << dataFileName << endl;
            cout << "Starting with empty list." << endl;
            cout << "A new file will be created when saving." << endl;
            employeeCount = 0;
        }
    }

    void saveToFile() {
        ofstream fout(dataFileName);

        if (!fout) {
            cout << "Error opening file for writing!" << endl;
            return;
        }

        for (int i = 0; i < employeeCount; i++) {
            fout << employees[i].lastName << "|"
                << employees[i].firstName << "|"
                << employees[i].age << "|"
                << employees[i].salary << endl;
        }

        fout.close();
        cout << "Data saved to file: " << dataFileName << endl;
    }

    void addEmployee() {
        if (employeeCount >= MAX_EMPLOYEES) {
            cout << "Maximum number of employees reached!" << endl;
            return;
        }

        Employee newEmp;

        cout << "Enter last name: ";
        cin.getline(newEmp.lastName, MAX_NAME_LEN);
        trim(newEmp.lastName);

        cout << "Enter first name: ";
        cin.getline(newEmp.firstName, MAX_NAME_LEN);
        trim(newEmp.firstName);

        cout << "Enter age: ";
        cin >> newEmp.age;
        cin.ignore();

        cout << "Enter salary: ";
        cin >> newEmp.salary;
        cin.ignore();

        employees[employeeCount] = newEmp;
        employeeCount++;
        cout << "Employee added!" << endl;
    }

    void editEmployee() {
        char searchLastName[MAX_NAME_LEN];
        cout << "Enter last name of employee to edit: ";
        cin.getline(searchLastName, MAX_NAME_LEN);
        trim(searchLastName);

        int index = -1;
        for (int i = 0; i < employeeCount; i++) {
            if (compareLastNames(employees[i].lastName, searchLastName)) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Employee not found!" << endl;
            return;
        }

        cout << "Editing employee: " << employees[index].lastName
            << " " << employees[index].firstName << endl;

        char newLastName[MAX_NAME_LEN];
        char newFirstName[MAX_NAME_LEN];

        cout << "New last name (" << employees[index].lastName << "): ";
        cin.getline(newLastName, MAX_NAME_LEN);
        trim(newLastName);
        if (stringLength(newLastName) > 0) {
            stringCopy(employees[index].lastName, newLastName);
        }

        cout << "New first name (" << employees[index].firstName << "): ";
        cin.getline(newFirstName, MAX_NAME_LEN);
        trim(newFirstName);
        if (stringLength(newFirstName) > 0) {
            stringCopy(employees[index].firstName, newFirstName);
        }

        cout << "New age (" << employees[index].age << "): ";
        int newAge;
        cin >> newAge;
        cin.ignore();
        if (newAge > 0) {
            employees[index].age = newAge;
        }

        cout << "New salary (" << employees[index].salary << "): ";
        double newSalary;
        cin >> newSalary;
        cin.ignore();
        if (newSalary >= 0) {
            employees[index].salary = newSalary;
        }

        cout << "Data updated!" << endl;
    }

    void deleteEmployee() {
        char searchLastName[MAX_NAME_LEN];
        cout << "Enter last name of employee to delete: ";
        cin.getline(searchLastName, MAX_BUFFER);
        trim(searchLastName);

        int index = -1;
        for (int i = 0; i < employeeCount; i++) {
            if (compareLastNames(employees[i].lastName, searchLastName)) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Employee not found!" << endl;
            return;
        }

        for (int i = index; i < employeeCount - 1; i++) {
            employees[i] = employees[i + 1];
        }
        employeeCount--;
        cout << "Employee deleted!" << endl;
    }

    void searchByLastName() {
        char searchLastName[MAX_NAME_LEN];
        cout << "Enter last name to search: ";
        cin.getline(searchLastName, MAX_NAME_LEN);
        trim(searchLastName);

        bool found = false;
        for (int i = 0; i < employeeCount; i++) {
            if (compareLastNames(employees[i].lastName, searchLastName)) {
                cout << "Last name: " << employees[i].lastName
                    << ", First name: " << employees[i].firstName
                    << ", Age: " << employees[i].age
                    << ", Salary: " << employees[i].salary << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No employees found with last name '" << searchLastName << "'." << endl;
        }
    }

    void displayByAge() {
        int age;
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();

        bool found = false;
        for (int i = 0; i < employeeCount; i++) {
            if (employees[i].age == age) {
                cout << "Last name: " << employees[i].lastName
                    << ", First name: " << employees[i].firstName
                    << ", Salary: " << employees[i].salary << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No employees found with age " << age << "." << endl;
        }
    }

    void displayByFirstLetter() {
        char letter;
        cout << "Enter letter: ";
        cin >> letter;
        cin.ignore();

        bool found = false;
        for (int i = 0; i < employeeCount; i++) {
            if (startsWithLetter(employees[i].lastName, letter)) {
                cout << "Last name: " << employees[i].lastName
                    << ", First name: " << employees[i].firstName
                    << ", Age: " << employees[i].age
                    << ", Salary: " << employees[i].salary << endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No employees found with last name starting with '" << letter << "'." << endl;
        }
    }

    void saveSearchResults() {
        char filename[MAX_BUFFER];
        cout << "Enter filename to save search results: ";
        cin.getline(filename, MAX_BUFFER);

        cout << "Select data type to save:" << endl;
        cout << "1. Employees of a specific age" << endl;
        cout << "2. Employees whose last name starts with a specific letter" << endl;
        cout << "Your choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        ofstream fout(filename);
        if (!fout) {
            cout << "Error creating file!" << endl;
            return;
        }

        if (choice == 1) {
            int age;
            cout << "Enter age: ";
            cin >> age;
            cin.ignore();

            fout << "Employees aged " << age << ":" << endl;
            fout << "----------------------------------------" << endl;

            for (int i = 0; i < employeeCount; i++) {
                if (employees[i].age == age) {
                    fout << "Last name: " << employees[i].lastName
                        << " | First name: " << employees[i].firstName
                        << " | Age: " << employees[i].age
                        << " | Salary: " << employees[i].salary << endl;
                }
            }
            cout << "Search results by age saved to file." << endl;
        }
        else if (choice == 2) {
            char letter;
            cout << "Enter letter: ";
            cin >> letter;
            cin.ignore();

            fout << "Employees whose last name starts with '" << letter << "':" << endl;
            fout << "----------------------------------------" << endl;

            for (int i = 0; i < employeeCount; i++) {
                if (startsWithLetter(employees[i].lastName, letter)) {
                    fout << "Last name: " << employees[i].lastName
                        << " | First name: " << employees[i].firstName
                        << " | Age: " << employees[i].age
                        << " | Salary: " << employees[i].salary << endl;
                }
            }
            cout << "Search results by letter saved to file." << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }

        fout.close();
    }

    void displayAll() {
        if (employeeCount == 0) {
            cout << "Employee list is empty." << endl;
            return;
        }

        cout << "\n=== ALL EMPLOYEES ===" << endl;
        for (int i = 0; i < employeeCount; i++) {
            cout << i + 1 << ". " << employees[i].lastName << " "
                << employees[i].firstName << ", " << employees[i].age
                << " years old, salary: " << employees[i].salary << endl;
        }
        cout << "========================\n" << endl;
    }

    void run() {
        int choice;

        loadFromFile();

        do {
            cout << "\n=== EMPLOYEE INFORMATION SYSTEM ===" << endl;
            cout << "1. Add employee" << endl;
            cout << "2. Edit employee" << endl;
            cout << "3. Delete employee" << endl;
            cout << "4. Search by last name" << endl;
            cout << "5. Display employees by age" << endl;
            cout << "6. Display employees by first letter of last name" << endl;
            cout << "7. Save search results to file" << endl;
            cout << "8. Show all employees" << endl;
            cout << "9. Save data to file" << endl;
            cout << "0. Exit (automatic save)" << endl;
            cout << "Your choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
            case 1: addEmployee(); break;
            case 2: editEmployee(); break;
            case 3: deleteEmployee(); break;
            case 4: searchByLastName(); break;
            case 5: displayByAge(); break;
            case 6: displayByFirstLetter(); break;
            case 7: saveSearchResults(); break;
            case 8: displayAll(); break;
            case 9: saveToFile(); break;
            case 0:
                saveToFile();
                cout << "Data automatically saved. Goodbye!" << endl;
                break;
            default: cout << "Invalid choice!" << endl;
            }
        } while (choice != 0);
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    EmployeeSystem system;
    system.run();
    return 0;
}