#include<iostream>
using namespace std;
int swap(int x, int y)
{
	int temp = x;
	x=y;
	y=temp;
	
	return 0;
}

int main()
{
	
	int a = 10, b=20;
	cout<<"the before value of a is ="<<a<<" and the before value b = "<<b<<"\n";
	
	swap(a,b);
	
	cout<<"the after value of a is ="<<a<<" and the after value b = "<<b<<"\n";




return 0;	
}
	
	
//	the before value of a is =10 and the before value b = 20
//the after value of a is =10 and the after value b = 20

