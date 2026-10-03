#include "сomplex.h"
#include "сomplex.h"
#include <cmath>

using namespace std
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
	if (this->imag >= 0) {
		cout << " + " << this->imag << "i";
	}
	else {
		cout << " - " << -this->imag << "i";
	}
}


Complex Complex::operator+(const Complex& other) const
{
	return Complex(this->real + other.real, this->imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const
{
	return Complex(this->real - other.real, this->imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const
{
	double newReal = this->real * other.real - this->imag * other.imag;
	double newImag = this->real * other.imag + this->imag * other.real;
	return Complex(newReal, newImag);
}

Complex Complex::operator/(const Complex& other) const
{
	double denominator = other.real * other.real + other.imag * other.imag;
	if (denominator == 0) {
		throw "Complex: division by zero";
	}
	double newReal = (this->real * other.real + this->imag * other.imag) / denominator;
	double newImag = (this->imag * other.real - this->real * other.imag) / denominator;
	return Complex(newReal, newImag);
}

Complex Complex::operator+(double scalar) const
{
	return Complex(this->real + scalar, this->imag);
}

Complex Complex::operator-(double scalar) const
{
	return Complex(this->real - scalar, this->imag);
}

Complex Complex::operator*(double scalar) const
{
	return Complex(this->real * scalar, this->imag * scalar);
}

Complex Complex::operator/(double scalar) const
{
	if (scalar == 0) {
		throw "Complex: division by zero";
	}
	return Complex(this->real / scalar, this->imag / scalar);
}

Complex Complex::operator-() const
{
	return Complex(-this->real, -this->imag);
}

bool Complex::operator==(const Complex& other) const
{
	return this->real == other.real && this->imag == other.imag;
}

void Complex::operator=(const Complex& other)
{
	this->real = other.real;
	this->imag = other.imag;
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
	os << c.real;
	if (c.imag >= 0) {
		os << " + " << c.imag << "i";
	}
	else {
		os << " - " << -c.imag << "i";
	}
	return os;
}