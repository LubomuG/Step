#include <iostream>
#include <windows.h>

using namespace std;

struct Book
{
    char title[100];
    char author[100];
    char publisher[100];
    char genre[50];
};

int length(const char* str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

void copy(char* dest, const char* src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int compare(const char* str1, const char* str2)
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

void printAll(Book books[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nBook №" << i + 1 << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Publisher: " << books[i].publisher << endl;
        cout << "Genre: " << books[i].genre << endl;
    }
}

void editBook(Book books[], int n)
{
    int index;
    cout << "Enter book number to edit: ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > n)
    {
        cout << "Error!\n";
        return;
    }

    index--;

    cout << "New title: ";
    cin.getline(books[index].title, 100);

    cout << "New author: ";
    cin.getline(books[index].author, 100);

    cout << "New publisher: ";
    cin.getline(books[index].publisher, 100);

    cout << "New genre: ";
    cin.getline(books[index].genre, 50);
}

void searchByAuthor(Book books[], int n)
{
    char author[100];
    bool found = false;

    cin.ignore();
    cout << "Enter author: ";
    cin.getline(author, 100);

    for (int i = 0; i < n; i++)
    {
        if (compare(books[i].author, author) == 0)
        {
            cout << books[i].title << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Nothing found.\n";
}

void searchByTitle(Book books[], int n)
{
    char title[100];
    bool found = false;

    cin.ignore();
    cout << "Enter book title: ";
    cin.getline(title, 100);

    for (int i = 0; i < n; i++)
    {
        if (compare(books[i].title, title) == 0)
        {
            cout << "Author: " << books[i].author << endl;
            cout << "Publisher: " << books[i].publisher << endl;
            cout << "Genre: " << books[i].genre << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Book not found.\n";
}

void sortByTitle(Book books[], int n)
{
    Book temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare(books[j].title, books[j + 1].title) > 0)
            {
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void sortByAuthor(Book books[], int n)
{
    Book temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare(books[j].author, books[j + 1].author) > 0)
            {
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void sortByPublisher(Book books[], int n)
{
    Book temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare(books[j].publisher, books[j + 1].publisher) > 0)
            {
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 10;

    Book books[N] =
    {
        {"Kobzar", "Shevchenko", "Osvita", "Poetry"},
        {"Lisova pisnya", "Ukrainka", "Veselka", "Drama"},
        {"Tyhrolovy", "Bahryanyi", "Folio", "Novel"},
        {"Zakhar Berkut", "Franko", "KSD", "Historical"},
        {"Marusya Churai", "Kostenko", "A-BA-BA-HA-LA-MA-HA", "Novel"},
        {"Eneyida", "Kotlyarevsky", "Veselka", "Poem"},
        {"Kaydasheva sim'ya", "Nechuy-Levytsky", "Folio", "Story"},
        {"Chorna rada", "Kulish", "Osnova", "Historical"},
        {"Intermezzo", "Kotsyubynsky", "Folio", "Novella"},
        {"Misto", "Pidmohylny", "KSD", "Novel"}
    };

    int choice;

    do
    {
        cout << "\n1 - Print all books";
        cout << "\n2 - Edit book";
        cout << "\n3 - Search by author";
        cout << "\n4 - Search by title";
        cout << "\n5 - Sort by title";
        cout << "\n6 - Sort by author";
        cout << "\n7 - Sort by publisher";
        cout << "\n0 - Exit";
        cout << "\nYour choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            printAll(books, N);
            break;
        case 2:
            editBook(books, N);
            break;
        case 3:
            searchByAuthor(books, N);
            break;
        case 4:
            searchByTitle(books, N);
            break;
        case 5:
            sortByTitle(books, N);
            cout << "Sorted.\n";
            break;
        case 6:
            sortByAuthor(books, N);
            cout << "Sorted.\n";
            break;
        case 7:
            sortByPublisher(books, N);
            cout << "Sorted.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}