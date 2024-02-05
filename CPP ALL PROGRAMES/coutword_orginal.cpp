#include<iostream>
using namespace std;
#include<cctype>

int main()
{
	int count=0;
	//char str[]="this          is       hello       gold      self";

char str[]="this i h f l";	 char space=' ';
	for(int i=0; str[i] != '\0'; ++i){
		if(str[i] ==space){
		count++;
		while(str[i+1]==space)
		i++;
		}
		
	}
	
	cout<<"Total words are = "<<count+1;
	//cout<<total;
	
}
