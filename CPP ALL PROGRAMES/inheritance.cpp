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

};

class B : protected A
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
    int getX_B()
    {

        return getX();
    }
    void setX_B(int a)
    {
        setX(a);
    }
};


class C
{
    int z;
public:
    int getZ()
    {
        return z;
    }
    void setZ(int a)
    {
        z = a;
    }


    int getData()
    {
        cout<<"\n C::getData will return member z of class C \n";
        return z;
    }
    int getQ(){
    cout<<"hello \n";
    return 0;
    }
};

class D: public A, public C
{
    int q;
    public:
    int getQ()
    {
        return q;
    }
    void setQ(int a)
    {
        q = a;
    }
};

int main()
{
    B objB;

    objB.setX_B(10);//
    objB.setY(5);

    cout<<objB.getX_B()<<" "<<objB.getY()<<endl;

    D objD;
    objD.setX(15);
    objD.setZ(20);
    objD.setQ(30);
    cout<<"\n ambiguity demonstrated "<<objD.A::getData()<<endl;
    cout<<"\n ambiguity demonstrated "<<objD.C::getData()<<endl;


objD.
//objD.C::getQ();
    return 0;



}
