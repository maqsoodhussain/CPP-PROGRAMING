#include<iostream>
using namespace std;
#include<conio.h>
//check whether a number is positive or not using if

void isPositive(float num)
{
    if(num >= 0)
    {
        cout<<num<<" is positive\n";
    }
}

//check whether a number is positive or negative using if ... else

void isPositiveOrNegative(float num)
{
    if(num >= 0)
    {
        cout<<num<<" is positive \n";
    }
    else
    {
        cout<<num<<" is negative \n";
    }
}

//check whether a number is positive or negative or equal
//using if ... else if

void isPositiveOrNegativeOrEqual(float num)
{
    if(num > 0 )
    {
        cout<<num<<" is positive \n";
    }
    else if(num < 0)
    {
        cout<<num<<" is negative \n";
    }
    else
    {
        cout<<num<<" is zero \n";
    }

}


void dayOfWeek(int num)
{
    switch(num)
    {
    case 0:
        cout<<"sunday \n";
        break;

    case 1:
        cout<<"Monday \n";
        break;

    case 2:
        cout<<"Tuesday \n";

        break;
    case 3:
        cout<<"Wednesday \n";
        break;
    case 4:
        cout<<"Thursday \n";
        break;

    case 5:
        cout<<"Friday \n";

        break;

    case 6:
        cout<<"Saturday \n";
        break;

    default:
        cout<<"we follow seven day week \n";

    }
}




void printEvenNumbers(int num)
{
    for(int i=0; i<=num; i++)
    {
        cout<<"inside loop \n";
        if(i%2 == 0)
        cout<<i<<'  ';
    }
}


int main()
{

    int num;
    cout<<"enter number to check";

    cin>>num;
/*
    isPositive(num);
    isPositiveOrNegative(num);
    isPositiveOrNegativeOrEqual(num);

    dayOfWeek(2);

    dayOfWeek(7);
    dayOfWeek(9);

    char day[] = "sunday";

    dayOfWeekNumber(day);
 //   dayOfWeekNumber('monday');
    cout<<day<<endl;
*/
 printEvenNumbers(num);

    return 0;
}
