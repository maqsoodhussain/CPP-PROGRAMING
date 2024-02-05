
/*Created by maqsood hussain wani
this code is not best code their may be better code than this but 
you can use this for building logic and checking these problesms are solved 
if there is any Error or mistake feel fee to contact me */

	/*In this progrmes many things are done
		1. Get string from user
		2. Counting total string characters with space
		3. counting total spaces in string
		4. counting tatal aphabets 
		5. Counting Vowels and Consonants in string
		5. Counting total words in string 
	*/




#include<iostream>
using namespace std;

int main(){
	

	
	//deceraing MAX_LENGTH for string length 200 is lenght total you can enter characters
	const int MAX_LENGTH = 200;
	
	//str is char string with length 200
	char str[MAX_LENGTH];
	
	//space varible for checking spaces in string
	char space =' ';
	
	//counter varables for counting purposes
	int count_length=0;
	int count_space=0;
	
	//varibles for counting vowesl and consonants in string
	int vowel = 0;
	int consonant = 0;
	
	//varible for counting words in string
	int space_count = 0;
	
	cout<<endl;
	cout<<"Enter you name with out Special Charactes and numbers Only Alphabet\n";
	
	//use getline function for getting string from user parameters are string name and length of string
	cin.getline(str, 200);
	
	//counting how many characters are in string  and length and how many spaces in string
	
	for(int i=0; str[i] !='\0'; ++i){
		count_length++;
		
		//while loop is for counting spaces only
		while(str[i]==space){
			count_space++;
			break;
		}
	}
	 
	 cout<<endl;
	 
	cout<<"length of String with [Spaces]= "<<count_length<<endl;
	cout<<"Total spaces in string = "<<count_space<<endl;
	
	cout<<"Total characters in string without spaces = "<<count_length-count_space<<endl;
	
	cout<<endl;
	
	
	//know blow code counts vowels and consonants in string 
	
	
	for(int i=0; str[i] !='\0'; ++i){
		
		//checkig every string varible with captal and small vowels latters 
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'I' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U'){
			vowel++;;
		}else{
			consonant++;
			
			while(str[i]==space){
			i++;
			}
			
			
	}
		}
		
	
	
	
	 // print how many vowels and consonants 
	 cout<<endl;
	 cout<<"Vowels in string = "<<vowel<<endl;
	 cout<<"Consonants in string = "<<consonant;
	
	cout<<endl;
	
	/* logic for counting words is simply counting spaces + 1 because between 
	words their is space so space only is counted 
	//counting words in string*/
	 	for(int i=0; str[i] !='\0'; ++i){
		if(str[i]==space){
			space_count++;
			
			
			while(str[i+1]==space){
				i++;
			}
		
		}
			
		
		
	}
	  
	  cout<<endl;
	 // printing word count
	 
	 /*here we check if user type only ony one word then space_counter 
		 is not incremented to 1 so we check if space_counter is 0 then we decleare local 
		 varible and set it to 1*/
		 
		 
	 if(space_count == 0){
	 	int one  =1;
	 	cout<<"total words in string = "<<one;
	 }else{
	 	cout<<"Total words in string = "<<space_count+1<<endl;
	 }
	
	cout<<endl;
	return 0;
}
