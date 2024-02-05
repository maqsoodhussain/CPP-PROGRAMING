

#include <iostream>

 using namespace std;

#define MAX(a,b) ((a>b) ? a: b)
#define MAX_THREE (a,b,c) MAX(MAX(a, b), c)
int main(){

// Write C++ code here

cout<<< MAX_THREE (4,6,7)<<" IS GREATER ";
return 0;
}
