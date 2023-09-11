#include<iostream>
using namespace std;
//function prototype here
void evenodd(int[], int);


int main(){
	
	//declearing array 
	int arr[]={1,2,3,4,5};
	int size = 5;

	
	
	//print array elements using for loop
	for(int i=0; i<size; i++){
		cout<<i<<" element is = " <<arr[i]<<endl;
	}
	
	evenodd(arr,size);
	
}


//function that checks whheater elements of array are even or odd
void evenodd(int arr[], int size){
	
	for(int i=0; i<size; i++){
		
		if(arr[i] % 2 ==0){
			cout<<arr[i]<<" Even\n";
		}else{
			cout<<arr[i]<<" Odd\n";
		}
	}
}
