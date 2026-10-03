#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double real, double imag);
    double getReal() const;
    double getImag() const;

    void setReal(double real);
    void setImag(double imag);

    void print() const;

    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex operator+(double scalar) const;
    Complex operator-(double scalar) const;
    Complex operator*(double scalar) const;
    Complex operator/(double scalar) const;

    Complex operator-() const;

    bool operator==(const Complex& other) const;

    void operator=(const Complex& other);

    friend ostream& operator<<(ostream& out, const Complex& c);
    friend istream& operator>>(istream& in, Complex& c);
};



Complex::Complex()
{
    this->real = 0;
    this->imag = 0;
}

Complex::Complex(double real, double imag)
{
    this->real = real;
    this->imag = imag;
}



double Complex::getReal() const
{
    return this->real;
}

double Complex::getImag() const
{
    return this->imag;
}

void Complex::setReal(double real)
{
    this->real = real;
}

void Complex::setImag(double imag)
{
    this->imag = imag;
}


void Complex::print() const
{
    cout << this->real;

    if (this->imag >= 0)
    {
        cout << " + " << this->imag << "i";
    }
    else
    {
        cout << " - " << -this->imag << "i";
    }
}



Complex Complex::operator+(const Complex& other) const
{
    return Complex(
        this->real + other.real,
        this->imag + other.imag
    );
}


Complex Complex::operator-(const Complex& other) const
{
    return Complex(
        this->real - other.real,
        this->imag - other.imag
    );
}



Complex Complex::operator*(const Complex& other) const
{
    double newReal =
        this->real * other.real -
        this->imag * other.imag;

    double newImag =
        this->real * other.imag +
        this->imag * other.real;

    return Complex(newReal, newImag);
}



Complex Complex::operator/(const Complex& other) const
{
    double denominator =
        other.real * other.real +
        other.imag * other.imag;

    if (denominator == 0)
    {
        throw "Complex: division by zero";
    }

    double newReal =
        (this->real * other.real +
         this->imag * other.imag) / denominator;

    double newImag =
        (this->imag * other.real -
         this->real * other.imag) / denominator;

    return Complex(newReal, newImag);
}



Complex Complex::operator+(double scalar) const
{
    return Complex(
        this->real + scalar,
        this->imag
    );
}

Complex Complex::operator-(double scalar) const
{
    return Complex(
        this->real - scalar,
        this->imag
    );
}


Complex Complex::operator*(double scalar) const
{
    return Complex(
        this->real * scalar,
        this->imag * scalar
    );
}


Complex Complex::operator/(double scalar) const
{
    if (scalar == 0)
    {
        throw "Complex: division by zero";
    }

    return Complex(
        this->real / scalar,
        this->imag / scalar
    );
}



Complex Complex::operator-() const
{
    return Complex(
        -this->real,
        -this->imag
    );
}



bool Complex::operator==(const Complex& other) const
{
    return this->real == other.real &&
           this->imag == other.imag;
}


void Complex::operator=(const Complex& other)
{
    this->real = other.real;
    this->imag = other.imag;
}



friend ostream& operator<<(ostream& out, const Complex& c)
{
    out << c.real;

    if (c.imag >= 0)
    {
        out << " + " << c.imag << "i";
    }
    else
    {
        out << " - " << -c.imag << "i";
    }

    return out;
}



friend istream& operator>>(istream& in, Complex& c)
{
    cout << "Enter real part: ";
    in >> c.real;

    cout << "Enter imaginary part: ";
    in >> c.imag;

    return in;
}


int main()
{
    Complex a, b;

    cout << "Pershyi kompleksnyi chyslo:" << endl;
    cin >> a;

    cout << "\nDrugyi kompleksnyi chyslo:" << endl;
    cin >> b;

    cout << "\na = " << a << "\n";
    cout << "b = " << b << "\n\n";

    try
    {
        cout << "Dodavannya (a + b):   " << (a + b) << "\n";
        cout << "Vidnimannya (a - b): " << (a - b) << "\n";
        cout << "Mnozhennya (a * b):  " << (a * b) << "\n";
        cout << "Dilennya (a / b):    " << (a / b) << "\n";

        cout << "\na + 2 = " << (a + 2) << "\n";
        cout << "a - 2 = " << (a - 2) << "\n";
        cout << "a * 2 = " << (a * 2) << "\n";
        cout << "a / 2 = " << (a / 2) << "\n";

        cout << "\n-a = " << (-a) << "\n";
    }
    catch (const char* msg)
    {
        cout << "Error: " << msg << "\n";
    }

    cout << "\na == b: " << (a == b) << "\n";

    return 0;
}
