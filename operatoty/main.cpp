#include <iostream>
#include "complex.h"
#include "Drip.cpp"
using namespace std;

int main()
{
	// Complex a(3, 5);
	// Complex b(2, -4);

	// cout << "a = " << a << "\n";
	// cout << "b = " << b << "\n\n";

	// cout << "a + b = " << (a + b) << "\n";
	// cout << "a - b = " << (a - b) << "\n";
	// cout << "a * b = " << (a * b) << "\n";
	// cout << "a / b = " << (a / b) << "\n\n";

	// cout << "a + 2 = " << (a + 2) << "\n";
	// cout << "a - 2 = " << (a - 2) << "\n";
	// cout << "a * 2 = " << (a * 2) << "\n";
	// cout << "a / 2 = " << (a / 2) << "\n\n";

	// cout << "-a = " << (-a) << "\n";
	// cout << "a == b: " << (a == b) << "\n";

	// try {
	// 	Complex zero(0, 0);
	// 	cout << a / zero << "\n";
	// }
	// catch (const char* msg) {
	// 	cout << "Error: " << msg << "\n";
	// }




    Drib a, b;
 
	cout << "Pershyi drib:" << endl;
	a.vvid();
 
	cout << "Drugyi drib:" << endl;
	b.vvid();
 
	cout << "\na = " << a << "\n";
	cout << "b = " << b << "\n\n";
 
	try {
		cout << "Dodavannya (a + b):   " << (a + b) << "\n";
		cout << "Vidnimannya (a - b): " << (a - b) << "\n";
		cout << "Mnozhennya (a * b):  " << (a * b) << "\n";
		cout << "Dilennya (a / b):    " << (a / b) << "\n";
	}
	catch (const char* msg) {
		cout << "Error: " << msg << "\n";
	}
 
	cout << "\na == b: " << (a == b) << "\n";

	return 0;
}