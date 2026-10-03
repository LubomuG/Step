#pragma once
#include <iostream>

class Complex {
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

	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};