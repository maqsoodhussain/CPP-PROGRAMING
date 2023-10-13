#include<iostream>
using namespace std;

int main(){
	
	string str="12";//this is string number we also get this from user
	int dig;  // this varables gives only one by one 
	
	int number=0; // this varable combines all 
	
	for(int i=0; str[i]!='\0'; i++){  // loop runs till our string ends that when last element is null by default end = '\0'
		dig  = str[i] - '0'; 
		/* here we convert it in in asci  str[i] means '1' = 48 in decimal '0' = 47
		 48 - 47 = 1 so we gets first number save it to digit but we need all together
		 we use this number = number * 10 + dig;
		 first time  0 = 0 * 10 + 1; = 1
		 			 second time  1= 1 * 10 + 2; = 12 
								 last in number 12 is stored this actual nuber  							
		*/
		//cout<<dig;
		number = number * 10 + dig;
		
	}
	
	cout<<number; // here we print actual number that is integer 
}
