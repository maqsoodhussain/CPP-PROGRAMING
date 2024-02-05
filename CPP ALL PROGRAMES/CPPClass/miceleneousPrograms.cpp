int myVar=10;

extern float pi;
int factorial(int num)
{
    if(num == 1)
    return 1;
    else
    return num*factorial(num-1);
}

int sum(int a, int b)
{
    return a+b;
}

double areaOfCircle(double radius)
{
    return pi *radius*radius;
}
