#include<iostream>
#include "miceleneous.h"
#include "mathematics.h"
using namespace std;
extern int myVar;

float pi = 3.14;
int main()
{
cout<<"writing multifile programs"<<endl;
cout<<factorial(3)<<endl;
cout<<areaOfCircle(5)<<endl;

cout<<myVar<<endl;
cout<<circumfernce(10);
return 0;
}
