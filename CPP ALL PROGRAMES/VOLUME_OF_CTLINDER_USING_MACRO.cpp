


#include <iostream>
using namespace std;
//formulla for volume of cylinder pi*r*rth

#define VOL_CYLD(r,h) (3.14 * r * r *h)
int main() {

// Write C++ code here
int radius = 10;

int height = 5; 
cout<<" Volume of cylinder is "<<VOL_CYLD(radius, height);

return 0;
}
