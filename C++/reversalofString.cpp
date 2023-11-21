#include<iostream>

using namespace std;

/*void reverse(char myString)
{
	
}
*/
int main()
{
	
	int maxLength = 20;
	char myString[maxLength];
	char myStringRev[maxLength];

	cout<<"enter the string \n";
	
	
	cin.getline(myString, maxLength);
	
	cout<<myString;
	
	int j,i;
	for(i=(maxLength-3), j = 0; i>=0; i--,j++)
	{
		myStringRev[j]= myString[i];
	}
	
	
	cout<<endl;
	cout<<myStringRev;
	
	
	return 0;
}



