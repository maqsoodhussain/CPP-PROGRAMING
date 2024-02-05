#include<iostream>
using namespace std;

int sumOfArrayElements(int [], int);
void incrementArrayElements(int [], int);

int main()
{
int x[5] = {1,3,2,4,2};
int i;
for( i=0; i<5;i++)
{
cout<<x[i]<<endl;
}
cout<<endl;

cout<<"values before increment function \n";
for( i=0; i<5;i++)
{
cout<<*(x+i)<<endl;
}
cout<<endl;

incrementArrayElements(x,5);
cout<<"values after increment function \n";
for( i=0; i<5;i++)
{
cout<<*(x+i)<<endl;
}

cout<<endl;

cout<<x;

cout<<"sum of elements of the array is = \n";
cout<<sumOfArrayElements(x, 5);

}


int sumOfArrayElements(int a[],int size)
{
    int sum=0;

    for(int i=0; i<size;i++)
    sum =sum + a[i];

    return sum;
}

void incrementArrayElements(int a[],int size)
{

    for(int i=0; i<size;i++)
    a[i] = a[i] + 1;

}
