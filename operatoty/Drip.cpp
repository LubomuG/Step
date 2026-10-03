#include "Drib.h"
#include <cstdlib>

using namespace std;

Drib::Drib()
{
	this->chyselnyk = 0;
	this->znamennyk = 1;
}

Drib::Drib(int chyselnyk, int znamennyk)
{
	if (znamennyk == 0) {
		throw "Drib: znamennyk ne mozhe buty 0";
	}
	this->chyselnyk = chyselnyk;
	this->znamennyk = znamennyk;
	skorotyty();
}

void Drib::skorotyty()
{
	if (znamennyk < 0) {
		znamennyk = -znamennyk;
		chyselnyk = -chyselnyk;
	}

	int a = abs(chyselnyk);
	int b = abs(znamennyk);

	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}

	if (a != 0) {
		chyselnyk /= a;
		znamennyk /= a;
	}
}

void Drib::vvid()
{
	cout << "Chyselnyk: ";
	cin >> chyselnyk;

	cout << "Znamennyk: ";
	cin >> znamennyk;

	while (znamennyk == 0) {
		cout << "Znamennyk ne mozhe buty 0. Vvedit shche raz: ";
		cin >> znamennyk;
	}

	skorotyty();
}

void Drib::vyvid() const
{
	cout << chyselnyk << "/" << znamennyk << endl;
}

int Drib::getChyselnyk() const
{
	return this->chyselnyk;
}

int Drib::getZnamennyk() const
{
	return this->znamennyk;
}

Drib Drib::operator+(const Drib& other) const
{
	int newChyselnyk = this->chyselnyk * other.znamennyk
	                  + other.chyselnyk * this->znamennyk;
	int newZnamennyk = this->znamennyk * other.znamennyk;

	return Drib(newChyselnyk, newZnamennyk);
}

Drib Drib::operator-(const Drib& other) const
{
	int newChyselnyk = this->chyselnyk * other.znamennyk
	                  - other.chyselnyk * this->znamennyk;
	int newZnamennyk = this->znamennyk * other.znamennyk;

	return Drib(newChyselnyk, newZnamennyk);
}

Drib Drib::operator*(const Drib& other) const
{
	int newChyselnyk = this->chyselnyk * other.chyselnyk;
	int newZnamennyk = this->znamennyk * other.znamennyk;

	return Drib(newChyselnyk, newZnamennyk);
}

Drib Drib::operator/(const Drib& other) const
{
	if (other.chyselnyk == 0) {
		throw "Drib: dilyty na 0 ne mozhna";
	}

	int newChyselnyk = this->chyselnyk * other.znamennyk;
	int newZnamennyk = this->znamennyk * other.chyselnyk;

	return Drib(newChyselnyk, newZnamennyk);
}

bool Drib::operator==(const Drib& other) const
{
	return this->chyselnyk == other.chyselnyk && this->znamennyk == other.znamennyk;
}

ostream& operator<<(ostream& os, const Drib& d)
{
	os << d.chyselnyk << "/" << d.znamennyk;
	return os;
}