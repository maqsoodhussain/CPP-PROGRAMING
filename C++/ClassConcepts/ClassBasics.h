#ifndef CLASSBASICS_H_INCLUDED
#define CLASSBASICS_H_INCLUDED

class Student
{
private:
    int stdId;
    char *stdName;
    char stdGender;

public:

    Student();
    Student(int);
    Student(Student &);

    int getStdId();
    char* getStdName();
    char getStdGender();

    void setStdId(int);
    void setStdName(char []);
    void setStdGender(char);

};


#endif // CLASSBASICS_H_INCLUDED
