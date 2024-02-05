#include <iostream>

using namespace std;


class Student
{
private:
    int stdId;
    char *stdName;

public:
    Student();
    Student(int);
    Student(Student &);

    int getStdId();
    char* getStdName();
    int setStdId(int);
    int setStdName(char []);


};



Student::Student()
{
    stdId = 0;
    stdName = "bogeyman";
}

Student::Student(int id)
{
    stdId = id;
    stdName = "spiderman";
}

Student::Student(Student &stdCopy)
{
    stdId = stdCopy.stdId;
    stdName = stdCopy.stdName;

}

int Student::getStdId()
{
    return stdId;
}

char* Student::getStdName()
{
    return stdName;
}

int Student::setStdId(int id)
{
    stdId = id;
    return 0;
}
int Student::setStdName(char name[])
{
    stdName = name;
    return 0;
}




int main()
{
    cout << "Hello world!" << endl;

     Student student1;  //invokes default constructor Student()
    cout<<"student 1 name is "<<student1.getStdName()<<endl;

     Student student2(12);  //invokes parametrized constructor Student(int)
    cout<<"student "<<student2.getStdId()<<"  name is "<<student2.getStdName()<<endl;

//Student student3(student2);
 Student student3= student2;  //invokes   (implicit or explicit) copy constructor  Student(&)
    cout<<"student "<<student3.getStdId()<<"  name is "<<student3.getStdName()<<endl;

student3.setStdName("steelman");





cout<<"after image is "<<endl;
cout<<"student "<<student2.getStdId()<<"  name is "<<student2.getStdName()<<endl;
 cout<<"student "<<student3.getStdId()<<"  name is "<<student3.getStdName()<<endl;



    return 0;
}
