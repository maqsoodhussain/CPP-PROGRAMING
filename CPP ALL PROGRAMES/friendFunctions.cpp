#include<iostream>

using namespace std;

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

    friend void friendA1(A &);
    friend void friendA2(A );
};

 void friendA1(A &obj)
    {
       cout<<"\n entered friendA1 friend function "<<endl;
        cout<<"\n the value of member x "<< obj.x<<endl;
cout<<"\n exited friendA1 friend function "<<endl;
    }
void friendA2(A obj)
    {
       cout<<"\n entered friendA2 friend function "<<endl;
        obj.x = obj.x + 10;
cout<<"\n exited friendA2 friend function "<<endl;
    }


    int main()
    {

        A obj1;

        obj1.setData(10);
        cout<<"\n the value of member x "<<obj1.getData()<<endl;

        friendA1(obj1);

        friendA2(obj1);

        friendA1(obj1);

        cout<<"\n the value of member x "<<obj1.getData()<<endl;

    return 0;

    }
