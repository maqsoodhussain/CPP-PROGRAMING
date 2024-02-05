#include<iostream>
using namespace std;

int main()
{

int i;
char myArray[5];

for(i=0;i<4;i++)
{
    cin>>myArray[i];
}

myArray[i] = '\0';

cout<<myArray;

return 0;
}
