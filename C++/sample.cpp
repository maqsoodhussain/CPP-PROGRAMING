#include<iostream>
using namespace std;

/*
this is a sample program to teach
the structure of a c++ program
*/
int main()
{
    int x,y;
    // cout is the object used to output a string or data value to the display of the computer
    cout<<"hello world! \n"<<endl;
    cout<<"this "<< "is"<<"awesome \n";
    cout<<"10 + 20 = "<< 10+20 <<endl;


    int i=1;

    while(i<2)
    {

        cout<<"enter the two integers to be added\n";
        cin>>x;
        cin>>y;
        cout<<"x + y = "<< x+y <<endl;

        i= i+1;
    }


    cout<<"enter the two integers to be used in division\n";
    cin>>x;
    cin>>y;

    if(y==0)
    {
        cout<<"y can not be zero"<<endl;
        cout<<"it is an error condition"<<endl;
    }
    else
    {

        cout<<"x / y = " << x/y<< endl;
        cout<<"x % y = "<<x%y<<endl;
    }
    return 0;
}
