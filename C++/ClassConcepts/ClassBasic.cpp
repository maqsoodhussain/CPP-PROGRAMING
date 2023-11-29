#include "ClassBasics.h"

Student::Student()
{
    stdId = 0;
    stdName = "bogeyman";
    stdGender = 'F';
}

Student::Student(int id)
{
    stdId = id;
    stdName = "FINMAN";
    stdGender = 'M';
}

Student::Student(Student &stdCopy)
{
    stdId = stdCopy.stdId;
    stdName = stdCopy.stdName;
    stdGender = stdCopy.stdGender;

}

int Student::getStdId()
{
    return stdId;
}

char* Student::getStdName()
{
    return stdName;
}
char Student::getStdGender()
{
    return stdGender;
}

void Student::setStdId(int id)
{
    stdId = id;

}
void Student::setStdName(char name[])
{
    stdName = name;

}

void Student::setStdGender(char gender)
{
    stdGender = gender;

}


