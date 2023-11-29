#include<iostream>
using namespace std;

int main()
{
	int x;
	int y;
	x=10;
	y=20;
	cout<<"the value of x is ="<<x<<" and the value y = "<<y<<"\n";
	
	// declaring reference variable
	int &a = x;
	int &b = y;
	cout<<"the value of x is ="<<a<<" and the value y = "<<b<<"\n";
	
}


//the value of x is =10 and the value y = 20
//the value of x is =10 and the value y = 20
