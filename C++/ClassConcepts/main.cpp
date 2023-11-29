#include <iostream>
#include "ClassBasics.h"
using namespace std;
//class Student;
int main()
{
    cout << "Hello world!" << endl;

     Student student1;  //invokes default constructor Student()
    cout<<"student "<<student1.getStdName()
        <<" has id "<<student1.getStdId() << " and gender "
        <<student1.getStdGender() << endl;

     Student student2(1);  //invokes parametrized constructor Student(int)
    cout<<"student "<<student2.getStdName()
        <<" has id "<<student2.getStdId() << " and gender "
        <<student2.getStdGender() << endl;

     Student student3(student2);  //invokes copy constructor Student(Student &)
    cout<<"student "<<student3.getStdName()
        <<" has id "<<student3.getStdId() << " and gender "
        <<student3.getStdGender() << endl;

    return 0;
}
