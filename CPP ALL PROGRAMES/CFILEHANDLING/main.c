#include <stdio.h>
#include <stdlib.h>

struct Student {
int rollNo;
int marks;
};



int freadFwriteDemo()
{
  FILE *fp;
  struct Student std1;
int i;
  fp = fopen("outputFwrite.bin","wb");

  for( i=1;i<=3;i++)
  {
      printf("enter the student %d rollNo\n",i);
      scanf("%d",&std1.rollNo);
      printf("enter the student %d marks \n",i);
      scanf("%d",&std1.marks);

      fwrite(&std1, sizeof(struct Student),1,fp);
  }

  fclose(fp);
  fp = fopen("outputFwrite.bin","rb");

  for(i=1;i<=3;i++)
  {
      fread(&std1, sizeof(struct Student),1,fp);

      printf(" the student %d rollNo \n",i);
      printf("%d",std1.rollNo);
      printf(" the student %d marks \n",i);
      printf("%d",std1.marks);


  }

  fclose(fp);
}


int readFileText()
{
    FILE *fp1;
    int i;
    int sum = 0;
    fp1= fopen("int_bin.txt","w");

    for(i=0; i<=10; i++)
    {
        fprintf(fp1,"%d\n",i);

    }
    fclose(fp1);


    fp1= fopen("int_bin.txt","r");

    while((fscanf(fp1,"%d",&i))!=EOF)
    {
        sum = sum + i ;
        printf("%d \n", i);
    }

    fclose(fp1);

    printf("the sum of integers read from file = %d\n",sum);
}

int readFile()
{
    FILE *fp1;
    int i;
    int sum = 0;
    fp1= fopen("int_bin.bin","w");

    for(i=0; i<=10; i++)
    {
        putw(i,fp1);

    }
    fclose(fp1);


    fp1= fopen("int_bin.bin","r");

    while((i=getw(fp1))!=EOF)
    {
        sum = sum + i ;
        printf("%d \n", i);
    }

    fclose(fp1);

    printf("the sum of integers read from file = %d\n",sum);
}

int readWriteFileDemo()
{
    FILE *fp1 = fopen("input","a");

    char c;

    while((c = getchar()) != EOF)
        putc(c, fp1);

    fclose(fp1);

    fp1 = fopen("input","r");

    while((c=getc(fp1)) != EOF)
        printf("%c",c);

    fclose(fp1);
    return 0;
}


int main()
{
    //readWriteFileDemo();

   // readFile();
   // readFileText();
   freadFwriteDemo();
    return 0;
}
