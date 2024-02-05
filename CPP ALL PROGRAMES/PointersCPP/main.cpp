#include <iostream>

using namespace std;

int main()
{
   int x=10;
   int *intPtr = &x;

   float y = 10.2;

   float * floatPtr = &y;
   cout<<intPtr - floatPtr;
   int *intPtr2 =  intPtr + 6;
   cout<<intPtr<<endl;
   cout<<intPtr2<<endl;

   cout<< intPtr - intPtr2<<endl;

   cout<<intPtr<<endl;

   intPtr  = intPtr + 3;
   cout<<intPtr<<endl;

/*   cout<<*intPtr<<endl;

   char charX = 'c';
   char *charPtr = &charX;
   cout<<*charPtr<<endl;

   double doubleX = 3.22;
   cout<<&doubleX<<endl;
   double *doublePtr = &doubleX;
   cout<<*doublePtr<<endl;



int myArray[] = {1,4,3};

cout<<myArray<<endl;

cout<<myArray[0]<<endl;
cout<<*(myArray + 0)<<endl;
cout<<*(myArray)<<endl;

cout<<myArray[2]<<endl;
cout<<*(myArray + 2)<<endl;

cout<<myArray[3]<<endl;
cout<<*(myArray + 3)<<endl;

cout<<sizeof(int)<<endl;
cout<<sizeof(double)<<endl;
cout<<sizeof(char)<<endl;
cout<<sizeof(3)<<endl;
cout<<sizeof(3.6)<<endl;

cout<<sizeof(myArray)<<endl;
cout<<sizeof(myArray)/sizeof(int)<<endl;



int *sPtr = &x;
cout<<*sPtr<<endl;

int **dPtr = &sPtr;
cout<<**dPtr<<endl;


*/
    return 0;
}
