#include <iostream>
using namespace std;

template <typename T>
T getMax(T *arr, int size)
{
    T max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

template <typename T>
T getMin(T *arr, int size)
{
    T min = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    return min;
}

template <typename T>
void sortArr(T *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
int binarySearch(T *arr, int size, T value)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;

        if (arr[middle] == value)
        {
            return middle;
        }

        if (arr[middle] < value)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return -1;
}

template <typename T>
void replaceElement(T *arr, int size, int index, T value)
{
    if (index < 0 || index >= size)
    {
        cout << "Index is out of range!" << endl;
        return;
    }

    arr[index] = value;
}

template <typename T>
void printArr(T *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int size;

    cout << "Enter size: ";
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " number: ";
        cin >> arr[i];
    }

    cout << "Max: " << getMax(arr, size) << endl;
    cout << "Min: " << getMin(arr, size) << endl;

    sortArr(arr, size);

    cout << "Sorted: ";
    printArr(arr, size);

    int value;
    cout << "Enter value to search: ";
    cin >> value;

    cout << "Index: " << binarySearch(arr, size, value) << endl;

    int index;
    cout << "Enter index to replace: ";
    cin >> index;

    cout << "Enter new value: ";
    cin >> value;

    replaceElement(arr, size, index, value);

    cout << "After replace: ";
    printArr(arr, size);

    delete[] arr;

    return 0;
}

// done finally