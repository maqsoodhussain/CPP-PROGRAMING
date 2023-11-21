#include<iostream>
using namespace std;

 int main(int argc, char * argv[])
 {
     cout<<"the number of arguments passed at command  line is "
            <<argc<<endl;
            cout<<"command line arguments are";
      for(int i=0;i<argc;i++)
      {
          cout<<argv[i]<<endl;
      }
     return 0;
 }
