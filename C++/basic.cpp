#include<iostream>
using namespace std;
//program to perform sum of two integers
int main()
{
    int x,y;
    /*
    cin>>x;
    cin>>y;
    */
    x=10;
    y=20;

    int *pX,*pY;
    pX= &x;
    pY = &y;

    cout<<x<<endl;  //10
    cout<<*pX<<endl;  //10
    cout<<pX<<endl;   //&x
    cout<<&x<<endl;

    cout<<y<<endl;    //20
    cout<<*pY<<endl;   //20
    cout<<pY<<endl;    //&y
    cout<<&y<<endl;

    int &ref = x;

cout<<ref<<endl;
ref--;

cout<<x<<endl;
cout<<ref<<endl;
    return 0;
}
