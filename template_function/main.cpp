// #include <iostream>
// #include <cmath>
// using namespace std;

// /*template <typename T>
// double Avarage(T* arr, int length)
// {
//     T suma = 0;
//     for(int i = 0; i< length; i++){
//         suma += arr[i];
//     }
//     return suma/length;
// }
// */

// class Roots
// {
// private:
//     double x1;
//     double x2;
//     bool rootsExist;

// public:
//     Roots()
//     {
//         rootsExist = false;
//     }
//     Roots(double x)
//     {
//         rootsExist = true;
//         x1 = x2 = x;
//     }
//     Roots(double x1, double x2)
//     {
//         rootsExist = true;
//         this->x1 = x1;
//         this->x2 = x2;
//     }

//     double getx1()
//     {
//         if (rootsExist)
//         {
//             return x1;
//         }
//         else
//         {
//             throw "Error";
//         }
//     }

//     double getx2()
//     {
//         if (rootsExist)
//         {
//             return x2;
//         }
//         else
//         {
//             throw "Error";
//         }
//     }
// };

// template <typename T>
// T lineequation(T a, T b)
// {
//     return (-b) / a;
// };
// template <typename T>
// Roots Quadratic(T a, T b, T c)
// {
//     double D = b * b - (4 * a * c);
//     if (D < 0)
//     {
//         return Roots();
//     }
//     else if (D > 0)
//     {

//         double x1 = (-b + sqrt(D)) / (2 * a);
//         double x2 = (-b - sqrt(D)) / (2 * a);
//         return Roots(x1, x2);
//     }
//     else
//     {
//         double x = (-b) / 2 * a;
//         return Roots(x);
//     }
// }

// int main()
// {
//     /*int length = 13;
//     int arr[length];
//     for(int i = 0;i< length;i++)
//     {
//         arr[i] = i*5889986/7555.444+159.4;
//     }
//     cout << "[";
//     for(int i = 0; i< length; i++)
//     {
//         cout << arr[i] << ", ";
//     }
//     cout << "]" << endl;
//     cout << Avarage(arr, length) << endl;
//     return 0;*/

//     // ax^2 + bx +c= 0;
//     double a = 1;
//     double b = 5;
//     double c = 3;

//     Roots result = Quadratic(a, b, c);

//     try
//     {
//         cout << result.getx1() << endl
//              << result.getx2() << endl;
//     }
//     catch (const char[])
//     {
//         cout << "Roots dont exist" << endl;
//     }
// }

#include <iostream>
using namespace std;

template <typename T>
T FindMax(T first, T second)
{
    if (first > second)
    {
        return first;
    }
    else if (second > first)
    {
        return second;
    }
    else
    {
        throw "first = second";
    }
}

template <typename T>
T FindMin(T first, T second)
{
    if (first < second)
    {
        return first;
    }
    else if (second < first)
    {
        return second;
    }
    else
    {
        throw "first = second";
    }
}

int main()
{
    try
    {
        int first, second;

        cout << "Enter first number: ";
        cin >> first;

        cout << "Enter second number: ";
        cin >> second;

        cout << "Max: " << FindMax(first, second) << endl;
        cout << "Min: " << FindMin(first, second) << endl;
    }
    catch (const char *error)
    {
        cout << "Error: " << error << endl;
    }

    return 0;
}
