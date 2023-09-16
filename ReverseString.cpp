#include<iostream>
#include<cctype>
using namespace std;


int main(){
	
	int str_length =10;
    char str[str_length];
    char revstr[str_length];
    
    cout<<"Enter String "<<endl;
    cin.getline(str,str_length);
     
     
	cout<<endl;
	cout<<str;
	
	cout<<endl;
	int i, j;
	
	for(i=str_length-2, j=0; i>=0; i--,j++){
		
		//revstr[j]=str[i];
		//cout<<revstr[j]<<"h"<<endl;
		
			
			revstr[j] = str[i];
			//cout<<revstr[j];
		
		
		
	}
	
	
	cout<<revstr;
    return 0;
}
