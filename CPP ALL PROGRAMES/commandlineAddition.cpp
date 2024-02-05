#include<iostream>
#include<cstdlib>
using namespace std;

 int main(int argc, char * argv[])
 {
     int sum=0;
      for(int i=1;i<argc;i++)
      {
//          sum = sum + atoi(argv[i]);
 sum = sum + argv[i];
      }
      cout<<"the sum is "<<sum<<endl;
     return 0;
 }
