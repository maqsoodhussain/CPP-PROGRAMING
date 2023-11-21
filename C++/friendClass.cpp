#include<iostream>

using namespace std;
class B;
class C;
class A
{
private:
    int x;
public:

    void setData(int a)
    {
        x = a;
    }
    int getData()
    {
        return x;
    }

    friend class B;

void getDataC(C &);
};

class C
{
private:
    int abc;

public:
    void setData(int a)
    {
        abc = a;
    }
    int getData()
    {
        return abc;
    }


    friend void A::getDataC(C &);
};

void A::getDataC(C &obj)
    {
        cout<<"the value of member abc of Class B "<<obj.abc<<endl;
    }

class B
{
private:
    int y;

public:
    void setData(int a)
    {
        y = a;
    }
    int getData()
    {
        return y;
    }

    void getDataA(A obj)
    {
        cout<<"the value of member x of Class A "<<obj.x<<endl;
    }
};


int main()
{

    A obj1;

    obj1.setData(10);
    B obj2;

    obj2.getDataA(obj1);

    C obj3;

    obj3.setData(30);

    obj1.getDataC(obj3);

    return 0;

}
