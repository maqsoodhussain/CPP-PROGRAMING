#include<iostream>
using namespace std;

int main(){
	
	int a,b;
	cout<<"Enter two numbers: ";
	cin>>a>>b;
     
    cout<<"You Entered :- "<<a<<" "<<b<<endl;
    
    int temp = a;
        a = b;
        b = temp;
	
	cout<<endl;
	cout<<"After Swap :: "<<a<<" "<<b;    
	return 0;
}
