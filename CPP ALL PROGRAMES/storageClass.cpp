#include<iostream>
using namespace std;
int p; // global variable

void abc()
{
    static int numOfCalls;
    numOfCalls++;
cout<<"\n within abc";
    cout<<"\n"<<numOfCalls;
    cout<<"\n"<<p;
}
void xyz()
{
    int y=0; //auto
   register int z=0;
   z=z+1;
   cout<<"\n register variable"<<z;
    //y = y+1;
    //cout<<y;
}

int main()
{
    int x; //auto
cout<<"\n size of integer is "<<sizeof(x);
cout<<"\n size of integer is "<<sizeof(int);
cout<<"\n size of float is "<<sizeof(float);
cout<<"\n size of char is "<<sizeof(char);
cout<<"\n size of double is "<<sizeof(double);
cout<<"\n size of long double is "<<sizeof(long double);

char character  ;
character = 127 + 1; //overflow

cout<<"\n"<<(int)character;

character = -128 - 1; //underflow

cout<<"\n"<<(int)character;


    //cout<<"\n"<<x; //initial value is garbage
    //abc();
//    xyz();
  //  xyz();

    cout<<"\n"<<p;
    return 0;
}
