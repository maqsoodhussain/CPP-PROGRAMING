#include<iostream>
using namespace std;
 void fun(char *name);
int main(){
	 
	
	struct student{
		string name;
		int id;
		int dob;
	};
	 
	
	public : student s1;
	s1.name="maqood hussain";
	
	
	
	return 0;
}
void fun(char *name){
		string name1 = s1.name;
		cout<<name1;
	}
