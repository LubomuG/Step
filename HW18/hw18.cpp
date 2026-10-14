#include <iostream>
using namespace std;

class Pet
{
protected:
    string name;

public:
    Pet(string name)
    {
        this->name = name;
    }

    virtual void showInfo() const
    {
        cout << "Name: " << name << endl;
    }

    virtual void speak() const = 0;

    virtual ~Pet() {}
};

class Dog : public Pet
{
private:
    string breed;
    int age;

public:
    Dog(string name, string breed, int age) : Pet(name)
    {
        this->breed = breed;
        this->age = age;
    }

    void showInfo() const override
    {
        cout << "Dog" << endl;
        Pet::showInfo();
        cout << "Breed: " << breed << endl;
        cout << "Age: " << age << endl;
    }

    void speak() const override
    {
        cout << name << " says: Woof!" << endl;
    }
};

class Cat : public Pet
{
private:
    string color;
    bool isIndoor;

public:
    Cat(string name, string color, bool isIndoor) : Pet(name)
    {
        this->color = color;
        this->isIndoor = isIndoor;
    }

    void showInfo() const override
    {
        cout << "Cat" << endl;
        Pet::showInfo();
        cout << "Color: " << color << endl;
        cout << "Indoor: " << (isIndoor ? "yes" : "no") << endl;
    }

    void speak() const override
    {
        cout << name << " says: Meow!" << endl;
    }
};

class Parrot : public Pet
{
private:
    string species;
    bool canTalk;

public:
    Parrot(string name, string species, bool canTalk) : Pet(name)
    {
        this->species = species;
        this->canTalk = canTalk;
    }

    void showInfo() const override
    {
        cout << "Parrot" << endl;
        Pet::showInfo();
        cout << "Species: " << species << endl;
        cout << "Can talk: " << (canTalk ? "yes" : "no") << endl;
    }

    void speak() const override
    {
        if (canTalk)
        {
            cout << name << " says: Hello, Polly is a good bird!" << endl;
        }
        else
        {
            cout << name << " says: Tweet-tweet!" << endl;
        }
    }
};

class String
{
protected:
    char *str;
    int size;
    static int count;

public:
    String() : String(80) {}

    String(int size)
    {
        this->size = size;
        this->str = new char[size + 1];
        this->str[0] = '\0';
        count++;
    }

    String(const char *input)
    {
        int length = 0;
        while (input[length] != '\0')
        {
            length++;
        }
        this->size = length;
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = input[i];
        }
        this->str[length] = '\0';
        count++;
    }

    String(const String &other)
    {
        this->size = other.size;
        this->str = new char[size + 1];
        for (int i = 0; i <= size; i++)
        {
            this->str[i] = other.str[i];
        }
        count++;
    }

    String &operator=(const String &other)
    {
        if (this != &other)
        {
            delete[] str;
            this->size = other.size;
            this->str = new char[size + 1];
            for (int i = 0; i <= size; i++)
            {
                this->str[i] = other.str[i];
            }
        }
        return *this;
    }

    virtual ~String()
    {
        delete[] str;
        count--;
    }

    int getLength() const
    {
        int length = 0;
        while (str[length] != '\0')
        {
            length++;
        }
        return length;
    }

    void clear()
    {
        str[0] = '\0';
    }

    String operator+(const String &other) const
    {
        int len1 = getLength();
        int len2 = other.getLength();
        String result(len1 + len2);
        for (int i = 0; i < len1; i++)
        {
            result.str[i] = str[i];
        }
        for (int i = 0; i < len2; i++)
        {
            result.str[len1 + i] = other.str[i];
        }
        result.str[len1 + len2] = '\0';
        return result;
    }

    String &operator+=(const String &other)
    {
        *this = *this + other;
        return *this;
    }

    bool operator==(const String &other) const
    {
        int i = 0;
        while (str[i] != '\0' && other.str[i] != '\0')
        {
            if (str[i] != other.str[i])
            {
                return false;
            }
            i++;
        }
        return str[i] == other.str[i];
    }

    bool operator!=(const String &other) const
    {
        return !(*this == other);
    }

    void input()
    {
        cout << "Enter string: ";
        cin.getline(str, size + 1);
    }

    void output() const
    {
        cout << "string: " << str << endl;
    }

    static int getCount()
    {
        return count;
    }
};

int String::count = 0;

class BitString : public String
{
private:
    bool isValid() const
    {
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (str[i] != '0' && str[i] != '1')
            {
                return false;
            }
        }
        return true;
    }

    char *extended(int n) const
    {
        int length = getLength();
        char *result = new char[n + 1];
        char fill = (length == 0) ? '0' : str[0];
        for (int i = 0; i < n - length; i++)
        {
            result[i] = fill;
        }
        for (int i = 0; i < length; i++)
        {
            result[n - length + i] = str[i];
        }
        result[n] = '\0';
        return result;
    }

public:
    BitString() : String() {}

    BitString(const char *input) : String(input)
    {
        if (!isValid())
        {
            clear();
        }
    }

    BitString(const BitString &other) : String(other) {}

    BitString &operator=(const BitString &other)
    {
        String::operator=(other);
        return *this;
    }

    ~BitString() {}

    void negate()
    {
        int length = getLength();
        if (length == 0)
        {
            return;
        }

        bool isMin = (str[0] == '1');
        for (int i = 1; i < length && isMin; i++)
        {
            if (str[i] != '0')
            {
                isMin = false;
            }
        }

        int newLength = isMin ? length + 1 : length;
        char *buf = extended(newLength);

        for (int i = 0; i < newLength; i++)
        {
            buf[i] = (buf[i] == '0') ? '1' : '0';
        }

        for (int i = newLength - 1; i >= 0; i--)
        {
            if (buf[i] == '0')
            {
                buf[i] = '1';
                break;
            }
            buf[i] = '0';
        }

        delete[] str;
        str = buf;
        size = newLength;
    }

    BitString operator+(const BitString &other) const
    {
        int len1 = getLength();
        int len2 = other.getLength();
        if (len1 == 0)
        {
            return other;
        }
        if (len2 == 0)
        {
            return *this;
        }

        int n = (len1 > len2 ? len1 : len2) + 1;
        char *a = extended(n);
        char *b = other.extended(n);
        char *r = new char[n + 1];
        int carry = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            r[i] = '0' + (sum % 2);
            carry = sum / 2;
        }
        r[n] = '\0';

        BitString result(r);
        delete[] a;
        delete[] b;
        delete[] r;
        return result;
    }

    BitString &operator+=(const BitString &other)
    {
        *this = *this + other;
        return *this;
    }

    bool operator==(const BitString &other) const
    {
        int len1 = getLength();
        int len2 = other.getLength();
        if (len1 == 0 || len2 == 0)
        {
            return len1 == len2;
        }

        int n = len1 > len2 ? len1 : len2;
        char *a = extended(n);
        char *b = other.extended(n);
        bool equal = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                equal = false;
                break;
            }
        }
        delete[] a;
        delete[] b;
        return equal;
    }

    bool operator!=(const BitString &other) const
    {
        return !(*this == other);
    }
};

int main()
{
    cout << "=== Task 1 ===" << endl;
    Pet *pets[3] = {
        new Dog("Rex", "Shepherd", 4),
        new Cat("Kitty", "Gray", true),
        new Parrot("Polly", "Cockatiel", true)};
    for (int i = 0; i < 3; i++)
    {
        pets[i]->showInfo();
        pets[i]->speak();
        cout << endl;
        delete pets[i];
    }

    cout << "=== Task 2 ===" << endl;

    String str1;
    String str2(30);
    String str3("Hello, ");
    String str4("world");

    str1 = str3 + str4;
    str1.output();
    str3 += str4;
    str3.output();
    cout << "Length: " << str1.getLength() << endl;
    cout << "str1 == str3: " << (str1 == str3) << endl;
    cout << "str1 != str4: " << (str1 != str4) << endl;
    str1.clear();
    str1.output();
    str2.output();
    cout << "Objects created: " << String::getCount() << endl
         << endl;

    BitString x("0101");
    BitString y("0011");
    BitString z("10a1");

    x.output();
    y.output();
    cout << "Length of invalid: " << z.getLength() << endl;

    BitString sum = x + y;
    sum.output();

    BitString nx = x;
    nx.negate();
    nx.output();

    BitString zero = x + nx;
    zero.output();

    x += y;
    x.output();
    cout << "x == sum: " << (x == sum) << endl;
    cout << "x != y: " << (x != y) << endl;
    cout << "0101 == 00101: " << (BitString("0101") == BitString("00101")) << endl;

    BitString m("1000");
    m.negate();
    m.output();

    return 0;
}