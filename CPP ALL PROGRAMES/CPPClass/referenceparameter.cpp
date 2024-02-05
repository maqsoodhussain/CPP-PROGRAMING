#include<iostream>
using namespace std;
int abc=10;

int swap(int &x, int &y)
{
	int temp = x;
	x=y;
	y=temp;
	
cout<<abc<<endl;
	return 0;
}


void scoprule(){
	
	int abc=56;
	
	cout<<abc<<endl;
	
	for(int i =0; i<5;i++)
	{
	cout<<i<<endl;
	}
	
   
}


int main()
{
	/* 
		int a = 10, b=20;
	cout<<"the before value of a is ="<<a<<" and the before value b = "<<b<<"\n";
	
	swap(a,b);
	
	cout<<"the after value of a is ="<<a<<" and the after value b = "<<b<<"\n";


cout<<abc;

return 0;
*/	

scoprule();
return 0;
}
	
	
//the before value of a is =10 and the before value b = 20

//the after value of a is =20 and the after value b = 10

