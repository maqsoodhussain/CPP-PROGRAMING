// exceptions : run-time anamolies
//try, catch, throw

#include<iostream>
#include<string.h>
#include<exception> // std::set_terminate
#include<cstdlib>  //std::abort
using namespace std;

void myterminate(){
cout<<"this is my way of terminating the programm:terminate handler called";
abort();
}
void userDefinedException()
{
    int ageOfMother;
    int ageOfDaughter;
    try
    {
        cout<<"enter the age of mother\n";
        cin>>ageOfMother;
        cout<<"enter the age of daughter";
        cin>>ageOfDaughter;

        if(ageOfDaughter > ageOfMother)
            throw "can\'t be true";
    }
    catch(...)
    {
        cout<<"handled your exception"<<endl;
        cout<<"age of daughter can not be greater than age of mother"<<endl;
    }

}
void divisionByZero()
{
    int num1;
    int num2;
    try
    {
        cout<<"enter the num1\n";
        cin>>num1;
        cout<<"enter the num2\n";
        cin>>num2;

        if(num2==0) throw 99;

       if(num2>5)  throw 'c';



        cout<<num1/num2;

        int sum = num1 - num2;
        if (sum < 0) throw "num1 can not be less than num2";
    }


    catch(int i)
    {
     cout<<"denominator can not be zero"<<endl;
    }
    catch(char  c)
    {
     cout<<"denominator can not be above five"<<endl;
    }



}

int main()
{
    set_terminate(myterminate);

   // divisionByZero();
    //userDefinedException();



    throw 0;   //unhandled exception:calls terminate handler
    return 0;
}
