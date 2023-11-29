#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	char fname[] = "nayeem";
	char mname[] = "ahmad";
	char lname[] = "bhat";
	
	char name[30] = {' ' , '\0'};
	
	strcpy(name,fname);
	strcat(name," ");
	strcat(name,mname);
	strcat(name," ");
	strcat(name,lname);
	
	cout<<name<<endl;
	return 0;
	
}


//nayeem ahmad bhat

