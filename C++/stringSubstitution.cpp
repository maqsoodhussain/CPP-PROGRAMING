
#include<iostream>
using namespace std;

int main()
{
    char myString[] = "hello to the world of c Hope YOU ARE DOING WELL";
	char myStringMan[] = "hello to the world of c Hope YOU ARE DOING WELL";
	
    for(int i = 0; myString[i]!='\0'; i++)
    {
    
		 myStringMan[i] = myString[i]+10;
	}
    	
   	cout<<myString<<endl;
    
    	cout<<myStringMan<<endl;
    
    	return 0;
    }
    
 
