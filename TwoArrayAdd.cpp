#include<iostream>
using namespace std;

int main(){
	
	// decleraing arrays 
	
	int arr1[2][3]={   {1,2,3},
					   {3,4,5 }
	};
	
	int arr2[2][3]={   {1,2,3},
					   {3,4,9 }
	};
	
	
	//decleraing third array for sum  of two arrays
	int arr3[2][3];
	
	
	//printing first array
   for(int i=0; i<2; i++){
   	for(int j=0; j<3;j++){
   		cout<<" elements are = "<<arr1[i][j]<<endl;
	   }
   }
   
   
   
   //printing seond array
   cout<<"second array \n";
   for(int i=0; i<2; i++){
   	for(int j=0; j<3;j++){
   		cout<<" elements are = "<<arr2[i][j]<<endl;
	   }
   }
	
	//addition blow
	cout<<"addition is blow\n";
	 for(int i=0; i<2; i++){
   	for(int j=0; j<3;j++){
   		arr3[i][j] = arr1[i][j] + arr2[i][j];
   	
   		
	   }
   }
   
   
   //printing third array 
   cout<<"array three is given blow\n";
   for(int i=0; i<2; i++){
   	for(int j=0; j<3;j++){
   		cout<<" elements are = "<<arr3[i][j]<<endl;
	   }
   }
	
}
