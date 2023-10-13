#include<iostream>
using namespace std;

int main(){
	
	int a,b;
	cout<<"Enter two numbers: ";
	cin>>a>>b;
     
    cout<<"You Entered :- "<<a<<" "<<b<<endl;
    
    a = a + b ;
	b = a - b;
	a = a-b ;
	
	cout<<endl;
	cout<<"After Swap :: "<<a<<" "<<b;    
	return 0;
}
