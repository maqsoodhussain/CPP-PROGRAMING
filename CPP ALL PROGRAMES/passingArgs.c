#include<stdio.h>
#include<conio.h>
//int sumOfArrayElements(int [], int);
void incrementArrayElements(int [], int);

int main()
{
int x[5] = {1,3,2,4,2};
int i;

printf("values before increment function \n");
for( i=0; i<5;i++)
{
printf("%d \n",*(x+i));
}

printf("\n");
incrementArrayElements(x,5);
printf("values after increment function \n");
for( i=0; i<5;i++)
{
printf("%d\n",*(x+i));
}

printf("\n");


}



void incrementArrayElements(int a[],int size)
{
int i;
    for( i=0; i<size;i++)
    a[i] = a[i] + 1;

}
