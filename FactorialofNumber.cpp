#include<iostream>
using namespace std;

int main(){
//Program is factorial of given number
 int n;
 int fact=1;
 cout<<"Enter Number ";
 cin>>n;
 for(int i =1; i<=n; i++){
    fact = fact * i ;

 }
cout<<"Factorial of Given number "<<n <<" is "<<fact;

    return 0;
}