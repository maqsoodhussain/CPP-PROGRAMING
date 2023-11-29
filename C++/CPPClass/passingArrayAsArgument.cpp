#include<iostream>
using namespace std;

int arrayIncrementByFive(int arr[], int length)
{
	for(int i=0;i<length;i++)
	{
		arr[i] = arr[i] + 5;
	}
	return 0;
}


int main()
{
	
		int arr[4] = {10,20,30,40};
	cout<<"the before value of arr are \n";
	
	for(int i = 0;i<4;i++)
	cout<<" "<<arr[i];
	cout<<endl;

arrayIncrementByFive(arr,4);
	
cout<<"the after value of arr are \n";
	
	for(int i = 0;i<4;i++)
	cout<<" "<<arr[i];
	cout<<endl;
	
return 0;
	


}
	
	

