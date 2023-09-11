#include<iostream>
using namespace std;
//function prototype here
int arradd(int[], int);
int arrsub(int[], int);
int arrmult(int[], int);
float arrdiv(int[], int);



int main(){
	
	//declearing array 
	int arr[]={1,2,3,4,5};
	int size = 5;

	
	
	//print array elements using for loop
	for(int i=0; i<size; i++){
		cout<<i<<" element is = " <<arr[i]<<endl;
	}
	
	
	// calling funtion here
	int res=  arradd(arr, size);
	//print return function value
	cout<<"Sum of Array elements = "<< res;
	
	int sub = arrsub(arr, size);
	cout<<"Subtraction of Array elements = "<< sub;
	
	int mal1 = arrmult(arr, size);
	cout<<"Multiplication of Array elements = "<< mal1<<endl;
	
	float div= arrdiv(arr, size);
	cout<<"DIVISION of Array elements = "<< div;
	
	return 0;
}


//arradd function for addition 
int arradd(int arr[], int size){
		int sum=0;
		for(int i=0; i<size; i++){
		 sum = sum + arr[i];
	}
	cout<<"\n";
	return sum;
	
}

//arrsub function for subtraction
int arrsub(int arr[], int size){
		int sub=0;
			for(int i=0; i<size; i++){
			 sub = sub - arr[i];
		}
		cout<<"\n";
		return sub;
}

//arrmult function for multiply	
int arrmult(int arr[], int size){
			int mul=1;
			for(int i=0; i<size; i++){
			mul = mul * arr[i];
		}
		cout<<"\n";
		return mul;
}
	

//arrdiv for division	
float arrdiv(int arr[], int size){
			int div=1;
			for(int i=0; i<size; i++){
			div =  arr[i] / div;
			cout<<"  "<<div;
		}
		cout<<"\n";
		return div;
		
}
