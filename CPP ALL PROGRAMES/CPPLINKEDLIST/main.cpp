#include <iostream>

using namespace std;

struct Student
{
    int rollNo;
    Student *next;
};

void createList(Student ** stdList)
{

    Student *temp = NULL;
    temp = new Student;
    cin>>temp->rollNo;
    temp->next=NULL;

    if(*stdList == NULL)
    {
        *stdList = temp;
    }
    else
    {
        temp->next = *stdList;
        *stdList = temp;
    }


}
int main()
{
  Student *stdList=NULL;
  createList(&StdList);
    return 0;
}











// int  declaration at run time

int *ptr;
ptr = new int;


// int  array declaration at run time

int *ptr;
ptr = new int[10];


// Student array  declaration at run time

Student *ptr;
ptr = new Student[15];



