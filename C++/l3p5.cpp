#include<iostream>
using namespace std;

int main()
{

int myArray[10];
//read values from keyboard
for(int i=0;i<10;i++)
{
    cin>>myArray[i];
}

//declare array to hold frequency of each number
int freq[10];

//compute the frequency for each element after the first occurence
for(int i=0;i<10;i++)
{
    int count = 1;
    for(int j=i+1;j<10;j++)
    {
      if(myArray[i]==myArray[j])
      {
          count++;
      }
    }
    freq[i] = count;

}
for(int i=0;i<10;i++)
{
    cout<<myArray[i]<<"  "<<freq[i]<<endl;
}


return 0;
}
