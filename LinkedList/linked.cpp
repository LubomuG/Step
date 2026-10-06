#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(const T &value) : data(value), next(nullptr) {}
    };

    Node *head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList()
    {
        clear();
    }

    void insert(int pos, const T &value)
    {
        if (pos < 0 || pos > size)
        {
            throw out_of_range("Invalid position");
        }

        Node *newNode = new Node(value);

        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node *current = head;

            for (int i = 0; i < pos - 1; i++)
            {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }

        size++;
    }

    void deleteNode(int pos)
    {
        if (pos < 0 || pos >= size)
        {
            throw out_of_range("Invalid position");
        }

        Node *temp;

        if (pos == 0)
        {
            temp = head;
            head = head->next;
        }
        else
        {
            Node *current = head;

            for (int i = 0; i < pos - 1; i++)
            {
                current = current->next;
            }

            temp = current->next;
            current->next = temp->next;
        }

        delete temp;
        size--;
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Invalid index");
        }

        Node *current = head;

        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current->data;
    }

    const T &operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Invalid index");
        }

        Node *current = head;

        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current->data;
    }

    void clear()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }

        size = 0;
    }

    friend ostream &operator<<(ostream &os, const LinkedList<T> &list)
    {
        Node *current = list.head;

        while (current != nullptr)
        {
            os << current->data;

            if (current->next != nullptr)
            {
                os << " -> ";
            }

            current = current->next;
        }

        return os;
    }
};

int main()
{
    LinkedList<int> list;

    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(1, 15);

    cout << list << endl;

    cout << "Element [2]: " << list[2] << endl;

    list.deleteNode(1);

    cout << list << endl;

    list[1] = 100;

    cout << list << endl;

    return 0;
}