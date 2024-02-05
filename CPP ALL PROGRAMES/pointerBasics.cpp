// POINTERS IN C++

#include<iostream>
using namespace std;

int main()
{
	int x = 10;
	float y  = 4.5;
	char z  = 'A';
	
	int *ptrInt; //
	char* ptrChar;
	float *ptrFloat;
	
	cout<<x<<endl;
	cout<<y<<endl;
	cout<<z<<endl;
	
	cout<<ptrInt<<endl;
	
ptrInt = &x;

	cout<<*ptrInt<<endl;
	cout<<*(&x)<<endl;
	
	cout<<"something is wrong here \n";
	
	cout<<ptrInt<<endl;
	cout<<(ptrInt + 2)<<endl;
	
cout<<sizeof(int);	
	return 0;
	
}

/*
0x6ffe0c
0x6ffe14
4
