#include<iostream>
using namespace std;


int main()
{
	int vow=0,cont=0;
	char str[]="helloeee";
	
	for(int i=0; str[i] != '\0'; ++i){
		if(str[i] == 'a' ||  str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'){
		vow++;
		 
		}else{
		
			cont++;
	}
		
	}
	cout<<"Number of Vowels  = "<<vow<<endl;
	cout<<"Number of consonants = "<<cont;
	
}
