#include<iostream>
#include<String.h>
using namespace std;

class Person
{
private:
    string name;

public:
  string  getName()
    {
        return name;
    }
   void setName(string n)
    {
        name =n;
    }
};

void main()
{
    Person p1;

    p1.setName("sajid");

    cout<<"my name is "<<p1.getName()<<endl;
    //return 0;

}
