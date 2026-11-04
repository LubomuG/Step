#include <iostream>

using namespace std;

template <class T>
T &&MoveRef(T &value)
{
    return static_cast<T &&>(value);
}

template <class T>
class UniquePtr
{
private:
    T *ptr;

public:
    UniquePtr() : ptr(nullptr) {}
    explicit UniquePtr(T *p) : ptr(p) {}

    UniquePtr(const UniquePtr &) = delete;
    UniquePtr &operator=(const UniquePtr &) = delete;

    UniquePtr(UniquePtr &&other) : ptr(other.Release()) {}

    template <class U>
    UniquePtr(UniquePtr<U> &&other) : ptr(other.Release()) {}

    UniquePtr &operator=(UniquePtr &&other)
    {
        if (this != &other)
            Reset(other.Release());
        return *this;
    }

    ~UniquePtr() { delete ptr; }

    T *Release()
    {
        T *temp = ptr;
        ptr = nullptr;
        return temp;
    }

    void Reset(T *p = nullptr)
    {
        if (ptr != p)
        {
            delete ptr;
            ptr = p;
        }
    }

    T *Get() const { return ptr; }
    T *operator->() const { return ptr; }
    T &operator*() const { return *ptr; }
    explicit operator bool() const { return ptr != nullptr; }
};

template <class T>
class SharedPtr
{
private:
    T *ptr;
    int *count;

    void Drop()
    {
        if (count)
        {
            --(*count);
            if (*count == 0)
            {
                delete ptr;
                delete count;
            }
            ptr = nullptr;
            count = nullptr;
        }
    }

public:
    SharedPtr() : ptr(nullptr), count(nullptr) {}

    explicit SharedPtr(T *p) : ptr(p), count(p ? new int(1) : nullptr) {}

    SharedPtr(const SharedPtr &other) : ptr(other.ptr), count(other.count)
    {
        if (count)
            ++(*count);
    }

    SharedPtr &operator=(const SharedPtr &other)
    {
        if (this != &other)
        {
            Drop();
            ptr = other.ptr;
            count = other.count;
            if (count)
                ++(*count);
        }
        return *this;
    }

    ~SharedPtr() { Drop(); }

    int UseCount() const { return count ? *count : 0; }
    T *Get() const { return ptr; }
    T *operator->() const { return ptr; }
    T &operator*() const { return *ptr; }
    explicit operator bool() const { return ptr != nullptr; }
};

template <class T, class... Args>
UniquePtr<T> MakeUnique(Args &&...args)
{
    return UniquePtr<T>(new T(static_cast<Args &&>(args)...));
}

template <class T, class... Args>
SharedPtr<T> MakeShared(Args &&...args)
{
    return SharedPtr<T>(new T(static_cast<Args &&>(args)...));
}

class Food
{
public:
    virtual ~Food() {}
    virtual const char *GetName() const = 0;
    virtual int GetPrice() const = 0;
    virtual void Describe() const
    {
        cout << GetName() << " - $" << GetPrice() << endl;
    }
};

class Pizza : public Food
{
public:
    const char *GetName() const override { return "Pizza"; }
    int GetPrice() const override { return 12; }
};

class Burger : public Food
{
public:
    const char *GetName() const override { return "Burger"; }
    int GetPrice() const override { return 8; }
};

class Sushi : public Food
{
public:
    const char *GetName() const override { return "Sushi"; }
    int GetPrice() const override { return 15; }
};

class Pasta : public Food
{
public:
    const char *GetName() const override { return "Pasta"; }
    int GetPrice() const override { return 10; }
};

enum class OrderState
{
    Accepted,
    Preparing,
    Delivered
};

const char *StateToString(OrderState state)
{
    switch (state)
    {
    case OrderState::Accepted:
        return "Accepted";
    case OrderState::Preparing:
        return "Preparing";
    case OrderState::Delivered:
        return "Delivered";
    }
    return "Unknown";
}

class Order
{
private:
    static const int MAX_ITEMS = 10;

    int id;
    OrderState state;
    UniquePtr<Food> items[MAX_ITEMS];
    int itemCount;

public:
    explicit Order(int orderId) : id(orderId), state(OrderState::Accepted), itemCount(0) {}

    int GetId() const { return id; }
    OrderState GetState() const { return state; }

    void AddItem(UniquePtr<Food> item)
    {
        if (state != OrderState::Accepted)
        {
            cout << "Order #" << id << ": cannot add items after cooking has started" << endl;
            return;
        }
        if (itemCount >= MAX_ITEMS)
        {
            cout << "Order #" << id << ": order is full" << endl;
            return;
        }
        items[itemCount++] = MoveRef(item);
    }

    int GetTotal() const
    {
        int total = 0;
        for (int i = 0; i < itemCount; ++i)
            total += items[i]->GetPrice();
        return total;
    }

    bool SetState(OrderState newState)
    {
        if (static_cast<int>(newState) != static_cast<int>(state) + 1)
        {
            cout << "Order #" << id << ": cannot change state from "
                 << StateToString(state) << " to " << StateToString(newState) << endl;
            return false;
        }
        state = newState;
        cout << "Order #" << id << ": state changed to " << StateToString(state) << endl;
        return true;
    }

    bool NextState()
    {
        if (state == OrderState::Delivered)
        {
            cout << "Order #" << id << ": already delivered" << endl;
            return false;
        }
        return SetState(static_cast<OrderState>(static_cast<int>(state) + 1));
    }

    void Print() const
    {
        cout << "Order #" << id << " [" << StateToString(state) << "]" << endl;
        for (int i = 0; i < itemCount; ++i)
        {
            cout << "  ";
            items[i]->Describe();
        }
        cout << "  Total: $" << GetTotal() << endl;
    }
};

class OrderManager
{
private:
    static const int MAX_ORDERS = 20;

    SharedPtr<Order> orders[MAX_ORDERS];
    int orderCount;
    int nextId;

public:
    OrderManager() : orderCount(0), nextId(1) {}

    SharedPtr<Order> CreateOrder()
    {
        if (orderCount >= MAX_ORDERS)
        {
            cout << "Order limit reached" << endl;
            return SharedPtr<Order>();
        }
        SharedPtr<Order> order = MakeShared<Order>(nextId++);
        orders[orderCount++] = order;
        cout << "Order #" << order->GetId() << " accepted" << endl;
        return order;
    }

    SharedPtr<Order> FindOrder(int id) const
    {
        for (int i = 0; i < orderCount; ++i)
            if (orders[i]->GetId() == id)
                return orders[i];
        return SharedPtr<Order>();
    }

    void ProcessAll()
    {
        for (int i = 0; i < orderCount; ++i)
            while (orders[i]->GetState() != OrderState::Delivered)
                orders[i]->NextState();
    }

    void PrintAll() const
    {
        for (int i = 0; i < orderCount; ++i)
            orders[i]->Print();
    }
};

int main()
{
    OrderManager manager;

    SharedPtr<Order> first = manager.CreateOrder();
    first->AddItem(MakeUnique<Pizza>());
    first->AddItem(MakeUnique<Burger>());

    SharedPtr<Order> second = manager.CreateOrder();
    second->AddItem(MakeUnique<Sushi>());
    second->AddItem(MakeUnique<Pasta>());
    second->AddItem(MakeUnique<Pizza>());

    cout << endl
         << "Skipping a state" << endl;
    first->SetState(OrderState::Delivered);

    cout << endl
         << "Step by step" << endl;
    first->NextState();
    first->AddItem(MakeUnique<Pasta>());
    first->NextState();
    first->NextState();

    cout << endl
         << "Processing the rest" << endl;
    SharedPtr<Order> found = manager.FindOrder(2);
    if (found)
        found->NextState();
    manager.ProcessAll();

    cout << endl
         << "All orders" << endl;
    manager.PrintAll();

    return 0;
}