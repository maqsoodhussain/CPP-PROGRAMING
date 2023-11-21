
#include<iostream>
using namespace std;

class A
{
    int x;
public:
    int getX()
    {
        return x;
    }
    void setX(int a)
    {
        x = a;
    }

    int getData()
    {
        cout<<"\n A::getData will return member x of class A \n";
        return x;
    }

virtual void printData()
    {
        cout<<"\n A::printData will return member x of class A \n";

        cout<< x<<endl;
    }

};

class B : public A
{
    int y;
public:

    int getY()
    {
        return y;
    }
    void setY(int a)
    {
        y = a;
    }
    int getData()
    {
        cout<<"\n B::getData will return member y of class B \n";
        return y;
    }


void printData()
    {
        cout<<"\n B::printData will return member y of class B \n";

        cout<< y<<endl;
    }

};

int main()
{
    A objA;
    B objB;

    objA.setX(10);
    cout<<"\n the value of member x of object A"<<objA.getX()<<endl;
    objA.getData();

    objB.setX(10);
    cout<<"\n the value of member x of object A"<<objB.getX()<<endl;
    objB.getData();
    objB.A::getData();


    A *ptrBase;
    ptrBase = &objB;

    ptrBase->getData();
    ptrBase->printData();


}
