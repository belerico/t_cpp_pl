/*
    Redo §X.5[5], storing several (name,age) pairs in a class.
    Doing the reading and writing using your own >> and << operators
 */

#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

class Contacts
{
private:
    map<string, int> contacts;

public:
    Contacts() {}
    Contacts(initializer_list<pair<const string, int>> m) : contacts{m} {}
    int getAge(const string &name)
    {
        try
        {
            return contacts.at(name);
        }
        catch (out_of_range)
        {
            cout << "Sorry, but " << name << " does not appear in your contact list";
            return -1;
        }
    }
    void addFriend(const string &name, const int age)
    {
        try
        {
            char update;
            contacts.at(name);
            cout << name << " is already present in your contacts\nDo you want to update its his/her age? (yYnN): ";
            cin >> update;
            if (update == 'y' || update == 'Y')
                contacts[name] = age;
        }
        catch (out_of_range)
        {
            contacts[name] = age;
        }
    }

    map<string, int>::iterator begin()
    {
        return contacts.begin();
    }

    map<string, int>::iterator end()
    {
        return contacts.end();
    }
};

ostream &operator<<(ostream &os, Contacts &c)
{
    map<string, int>::iterator p = c.begin();
    map<string, int>::iterator end = --(c.end());
    for (; p != end; ++p)
        os << "Name: " << (*p).first << ", age: " << (*p).second << endl;
    os << "Name: " << (*p).first << ", age: " << (*p).second;
    return os;
}

istream &operator>>(istream &is, Contacts &c)
{
    int i = 0;
    char ch = ' ';
    bool lsqrb = 0, comma = 0;
    string name = "", age = "";
    is.ignore();
    while (is.get(ch) && ch != ']')
    {
        if (ch == '[' && !lsqrb)
            lsqrb = 1;
        else if (lsqrb && !comma)
        {
            if (isalpha(ch) || ch == ' ')
                name += ch;
            else if (ch == ',')
                comma = 1;
            else
            {
                cout << "Wrong input. An alphanumeric name must be inserted at " << i << endl;
                is.setstate(ios_base::failbit);
                return is;
            }
        }
        else if (lsqrb && comma)
        {
            if (isdigit(ch))
                age += ch;
            else if (ch == ' ')
                continue;
            else
            {
                cout << "Wrong input. A valid number must inserted at" << i << endl;
                is.setstate(ios_base::failbit);
                return is;
            }
        }
        else if (ch == ' ')
        {
            ++i;
            continue;
        }
        else
        {
            cout << "Wrong input. A valid input must be inserted at " << i << endl;
            is.setstate(ios_base::failbit);
            return is;
        }
        ++i;
    }
    c.addFriend(name, stoi(age));
    return is;
}

int main()
{
    int n;
    Contacts c1;
    Contacts c{{"Abigail", 23}, {"Federico", 27}};
    c.addFriend("Carola", 37);
    c.addFriend("Federico", 26);
    cout << "Carola is " << c.getAge("Carola") << " years old" << endl;
    cout << "Federico is " << c.getAge("Federico") << " years old" << endl;
    cout << "Your contatc list is composed by: \n"
         << c << endl;
    cout << "How many new friends do you want to insert? ";
    cin >> n;
    cout << "Insert a list of friend to add them to a new contact list (a valid input must be '[name1, age1]')" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << (i + 1) << ") ";
        cin >> c;
    }
    cout << "Your new contact list is composed by: \n"
         << c << endl;
}
