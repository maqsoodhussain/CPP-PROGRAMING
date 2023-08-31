#include<iostream>
using namespace std;

int main(){

   int n;
   int sum=0;
   int i;
cout<<"Enter number upto you want to add Even Number";
cin>>n;

   for(i=1; i<=n; i++){

    if( i  % 2 == 0){
        sum = sum + i;
    }
   }
cout<<"Sum of ever number is "<<sum;
return 0;

}