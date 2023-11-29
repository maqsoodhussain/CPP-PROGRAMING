#include <iostream>
#include<cstring>
#define MAX 2

using namespace std;

typedef struct
{
    char name[10];
    char rollNo[5];
    int marks;
} Student;

int displayStruct(Student s1)
{
    cout<<s1.rollNo<<" "<<s1.name<<" "<<s1.marks<<endl;
    return 0;
}
int  getStruct(Student *s1)
{
    strcpy(s1->name, "nayeem");

    strcpy((*s1).name, "nayeem");
    strcpy(s1->rollNo,"1313");
    s1->marks = 75;

    return 0;
}
int displayStructArray(Student stdArray[])
{
    for(int i=0; i<MAX; i++)
    {

        cout<<stdArray[i].rollNo<<" "<<stdArray[i].name
            <<" "<<stdArray[i].marks<<endl;
    }
    return 0;
}
int getStructArray(Student stdArray[])
{

    for(int i=0; i<MAX; i++)
    {
        char name[10];
        char rollNo[5];

        cin>>name;
        cin>>rollNo;

        strcpy(stdArray[i].name, name);
        strcpy(stdArray[i].rollNo,rollNo);

        cin>>stdArray[i].marks;
    }


    return 0;
}
int main()
{
    Student std1;

    getStruct(&std1);
    displayStruct(std1);

   // Student stdArray[MAX];

    //getStructArray(stdArray);
    //displayStructArray(stdArray);
    return 0;
}
