#include<iostream>
using namespace std;

#define PI 3.14
#define AREA(x) x*x
#define ADD(x, y) x+y
int main()
{

    int r = 7;
    int area  =  PI * r * r;

    cout<<"the area of the circle with radius "
     <<r<< " is "<<area<<endl;
int l= 5;

area  = AREA(l);
        l * l;
cout<<"\n the area of the square with side "
     <<l<< " is "<<area<<endl;


     cout<<"\n the sum  of two nums  "
     << " is "<<ADD(10, 20)<<endl;

     return 0 ;
}
