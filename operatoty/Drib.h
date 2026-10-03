#pragma once
#include <iostream>

class Drib
{
private:
	int chyselnyk;
	int znamennyk;

	void skorotyty();

public:
	Drib();
	Drib(int chyselnyk, int znamennyk);

	void vvid();
	void vyvid() const;

	int getChyselnyk() const;
	int getZnamennyk() const;

	Drib operator+(const Drib& other) const;
	Drib operator-(const Drib& other) const;
	Drib operator*(const Drib& other) const;
	Drib operator/(const Drib& other) const;

	bool operator==(const Drib& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Drib& d);
};