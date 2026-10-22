#include <iostream>
#include <string>

using namespace std;

struct Violation
{
    string date;
    string description;
    double fine;
    Violation *next;

    Violation(string d, string desc, double f)
    {
        date = d;
        description = desc;
        fine = f;
        next = nullptr;
    }
};

struct branch
{
    string key;
    Violation *head;
    Violation *tail;
    branch *left;
    branch *right;

    branch(const string &k, Violation *v)
    {
        key = k;
        head = v;
        tail = v;
        left = nullptr;
        right = nullptr;
    }

    void addViolation(Violation *v)
    {
        tail->next = v;
        tail = v;
    }

    ~branch()
    {
        while (head != nullptr)
        {
            Violation *tmp = head;
            head = head->next;
            delete tmp;
        }
    }
};

class GaiDatabase
{
private:
    branch *root;

    void insert_(branch *&b, const string &plate, Violation *v)
    {
        if (b == nullptr)
        {
            b = new branch(plate, v);
        }
        else if (plate == b->key)
        {
            b->addViolation(v);
        }
        else if (plate < b->key)
        {
            insert_(b->left, plate, v);
        }
        else
        {
            insert_(b->right, plate, v);
        }
    }

    branch *search_(branch *b, const string &plate) const
    {
        if (b == nullptr || b->key == plate)
            return b;
        if (plate < b->key)
            return search_(b->left, plate);
        return search_(b->right, plate);
    }

    void printNode(const branch *b) const
    {
        cout << "Number plate" << b->key << endl;
        int i = 1;
        double total = 0;
        for (const Violation *v = b->head; v != nullptr; v = v->next)
        {
            cout << "   " << i++ << ") " << v->date << " | " << v->description << " | fine: " << v->fine << " uan" << endl;
            total += v->fine;
        }
        cout << "   Total fine: " << total << " uan" << endl;
    }

    void printAll_(const branch *b) const
    {
        if ( b == nullptr) return;
        printAll_(b->left);
        printNode(b);
        printAll_(b->right);
    }

    void printRange_(const branch* b, const string& from, const string& to) const
    {
        if (b == nullptr) return;
        if(from < b->key) printRange_(b->left, from, to);
        if(from <= b->key && b->key <=to) printNode(b);
        if(b->key < to) printRange_(b->right, from, to);
    }

    void clear_(branch* b)
    {
        if(b == nullptr) return;
        clear_(b->left);
        clear_(b->right);
        delete b;
    }

    public:
    GaiDatabase() : root(nullptr) {}
    ~GaiDatabase()
    {
        clear_(root);
    }

    GaiDatabase(const GaiDatabase&) = delete;
    GaiDatabase& operator = (const GaiDatabase&) = delete;

    void addTicket(const string &plate, const string &date, const string &description, double fine)
    {
        insert_(root, plate, new Violation(date, description, fine));
    }

    void printAll() const
    {
        cout << "Full Gai Database: " << endl;
        if(root == nullptr) cout << "Datebase is empty" << endl;
        else printAll_(root);
    }

    void printByNumber(const string& plate) const 
    {
        cout << "Datebase by number: " << plate << endl;
        branch* b = search_(root, plate);
        if(b == nullptr) cout << "You did not do anything wrong"<< endl;
        else printNode(b); 
    }

    void printRange(const string& from, const string& to)
    {
        cout << "Numbers in range [ " << from << " ... " << to<< " ]" << endl;
        printRange_(root, from, to);
    }
};


int main() {
    GaiDatabase db;

    db.addTicket("AA1234BB", "01.03.2024", "Speeding", 340);
    db.addTicket("KA5555KA", "05.03.2024", "red light", 510);
    db.addTicket("AA1234BB", "12.04.2024", "Parking in a prohibited place", 255);
    db.addTicket("BC0007AX", "20.04.2024", "No seat belt", 340);
    db.addTicket("KA5555KA", "30.05.2024", "Speeding", 340);
    db.addTicket("AA1234BB", "15.06.2024", "Talking on the phone while driving", 510);

    db.printAll();
    cout << endl;
    db.printByNumber("KA5555KA");
    cout << endl;
    db.printByNumber("AA1234BB");
    cout << endl;
    db.printByNumber("A4BB");
    cout << endl;

    db.printRange("BC0007AX", "AA1234BB");

    return 0;
}