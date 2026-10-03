#include <iostream>
using namespace std;

class String 
{
    private:
    char* str;
    int size;
    static int count;
    public:
    String(): String(80){}

    String (int size)
    {
        this->size = size;
        this->str = new char[size + 1];
        this->str[0] = '\0';
        count++;
    }
    
    String(const char* input)
    {
        int length = 0;
        while (input[length] != '\0')
        {
            length++;
        }
        this->size = length;
        this->str = new char[length + 1];
        for(int i = 0;i < length; i++)
        {
            this->str[i] = input[i];
        }
        this->str[length] = '\0';
        count++;
    }
    ~String()
    {
        delete str;
        count--;
    }

    void input()
    {
        cout << "Введіть рядок: ";
        cin.getline(str, size + 1);
    }

    void output()
    {
        cout << "рядок: " << str << endl;

    }

    static int getCount()
    {
        return count;
    }
};

int String::count = 0;

int main ()
{
    String str1;
    String str2(30);
    String str3("Hello world");

    str1.input();
    str1.output();
    str2.output();
    str3.output();
    cout << "Кількість створених обєктів: " << String::getCount << endl;

    return 0;
}