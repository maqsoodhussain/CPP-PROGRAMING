#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class phonebook
{
    char name[80];
    char areacode[4];
    char prefix[4];
    char num[5];
public:
    phonebook() { };
    phonebook(char *n, char *a, char *p, char *nm)
    {
        strcpy(name, n);
        strcpy(areacode, a);
        strcpy(prefix, p);
        strcpy(num, nm);
    }
    friend ostream &operator<<(ostream &stream, phonebook o);
    friend istream &operator>>(istream &stream, phonebook &o);
};
// Display name and phone number.
ostream &operator<<(ostream &stream, phonebook o)
{
    stream << o.name << " ";
    stream << "(" << o.areacode << ") ";
    stream << o.prefix << "-";
    stream << o.num << "\n";
    return stream; // must return stream
}
// Input name and telephone number.
istream &operator>>(istream &stream, phonebook &o)
{
    cout << "Enter name: ";
    stream >> o.name;
    cout << "Enter area code: ";
    stream >> o.areacode;
    cout << "Enter prefix: ";
    stream >> o.prefix;
    cout << "Enter number: ";

    stream >> o.num;
    cout << "\n";
    return stream;
}
int main()
{
    phonebook a;
    char c;
    fstream pb("phone", ios::in | ios::out | ios::app);
    if(!pb)
    {
        cout << "Cannot open phone book file.\n";
        return 1;
    }
    for(;;)
    {
        do
        {
            cout << "1. Enter numbers\n";
            cout << "2. Display numbers\n";
            cout << "3. Quit\n";
            cout << "\nEnter a choice: ";
            cin >> c;
        }
        while(c<'1' || c>'3');
        switch(c)
        {
        case '1':
            cin >> a;    //read phonebook object from keyboard, call istream &operator>>(istream &stream, phonebook &o)
            cout << "Entry is: ";
            cout << a; // show on screen
            pb << a; // write phonebook object to disk,  call ostream &operator>>(ostream &stream, phonebook o)
            break;
        case '2':
            char ch;
            pb.seekg(0, ios::beg);    //seek pointer to the begginning of the file
            while(!pb.eof())            //while eof not read keep iterating
            {
                pb.get(ch);             // get a character from the file
                if(!pb.eof()) cout << ch;       //if read character not eof output to display
            }
            pb.clear(); // reset eof
            cout << endl;

            break;
        case '3':
            pb.close();
            return 0;
        }
    }
}
