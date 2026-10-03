#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class DynamikArr
{
    public:
    DynamikArr()
    {
        ARR[0] = 5;
    };
    ~DynamikArr();
    void checkSM()
    {
        arr.arr[0];
    }
    private:
    T* arr = new T[10];
};



/*
class DynamicArr
{
private:
 const int limit = 1000;
 int* arr;
 int capacity = 0;
 int length = 0;

public:

 DynamicArr()
 {
  this->arr = new int[0];
 }

 DynamicArr(const DynamicArr& copy)
 {
    this->length = copy.length;
    this->capacity = copy.capacity;
    this->arr = new int [capacity];
    for(int i = 0;i< this->length;i++)
    {
        this->arr[i] = copy.arr[i];
    }
 }


 DynamicArr(int size)
 {
  if (size > 0)
  {
   this->arr = new int[size];
   this->capacity = size;
  }
  else {
   this->arr = new int[0];
  }

 }
 ~DynamicArr()
 {
  delete arr;
 }
 int currentLength() const {
  return length;
 }
 int& getByindex(int index) const
 {
  if (index > 0 && index < length)
  {
   return arr[index];
  }
  else {
   throw "index is out of range";
  }
 }

 void pushBack(int elem)
 {
  if (this->length < this->capacity)
  {
   this->arr[this->length] = elem;
   this->length += 1;
  }
  else
  {
   if (this->capacity > 0) {
    this->capacity *= 2;
   }
   else
   {
    this->capacity += 10;
   }
   int* newArr = new int[this->capacity];
   for (int i = 0; i < this->length; i++) {
    newArr[i] = this->arr[i];
   }
   newArr[this->length] = elem;
   this->length += 1;
   this->arr = newArr;
   delete newArr;
  }


 }

 void pushEnywhere(int elem, int pos)
 {
  if (pos <= this->length) {
   if (pos == this->length) {
    this->pushBack(elem);
   }
   else
   {
    if (this->length == this->capacity) {
     if (this->capacity > 0) {
      this->capacity *= 2;
     }
     else
     {
      this->capacity += 10;
     }
     int* newArr = new int[this->capacity];
     for (int i = 0; i < pos; i++) {
      newArr[i] = this->arr[i];
     }
     newArr[pos] = elem;
     for (int i = pos; i < this->length; i++) {
      newArr[i + 1] = this->arr[i];
     }
     this->length += 1;
     this->arr = newArr;
     delete newArr;
    }
    else
    {
     int temp = this->arr[pos];
     this->arr[pos] = elem;
     for (int i = pos + 1; i < this->length; i++) {
      int temps = this->arr[i];
      this->arr[i] = temp;
      temp = temps;
     }
    }
   }
  }
  else
  {
   throw "nvalid position to insert";
  }
 }

 void deleteBack() {
  if (length > 0) {
   arr[length] = 0;
   length--;
  }
  else {
   throw "u bad at is";
  }
 };

 void deleteByIndex(int pos) {
  if (pos == length) {
   deleteBack();
  }
  else if (pos > length - 1) {
   throw "error";
  }
  else {

   for (int i = 0; i < length - 1; i++) {
    this->arr[i] = this->arr[i + 1];
   }
   length--;
  }
 }

 void shrinkToFit() {
  int* newArr = new int[length];

  for (int i = 0; i <= length; i++) {
   newArr[i] = this->arr[i];
  }

  delete arr;
  arr = newArr;
  newArr = nullptr;
 }


    friend ostream& operator<< (ostream& out, DynamicArr arr)
    {
        out << "[";
        for(int i = 0;i < arr.length; i++)
        {
            if (arr.length-1 != i)
            {
                out << arr.arr[i] << ", ";
            }
            else
            {
                out << arr.arr[i] << "]";
            }
        }
        return out;
    }

    friend istream& operator>> (istream& in, DynamicArr& arr)
    {
        cout << "enter count: ";
        in >> arr.length;
        delete arr.arr;
        arr.arr = new int [arr.length];
        arr.capacity = arr.length;

        for(int i = 0; i < arr.length; i++)
        {
            cout << "Enter " << i + 1 << " number: ";
            in >> arr.arr[i];
        }
        return in;
    }
};
*/
/*int add(int a, int b)
{
    return a+ b;
}

double add(double a, double b)
{
    return a-b;
}

template <typename T, typename T1, typename T2>
int add(T a, T1 b)
{
    T result = a+b;
    T1 result = a + b;
    if(result1 > result)
    {
        reutrn result1;
    }
    else
    {
        return result;
    }
}
*/
int main() {
    /* DynamicArr arr;
     cin >> arr;
     cout << arr;
     return 0;*/
    /*double a = 5.5;
    char sign = '-';
    double b = 10;
    cout << add(a, b);

    int a1 = 5;
    int b1 = 10;
    cout << add(a1, b1);*/


    DynamikArr<int> a;
    DynamikArr<double> b;
    DynamikArr<char> c;
    return 0;
}