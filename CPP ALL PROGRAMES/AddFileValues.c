#include<stdio.h>



void  WriteInFile(){

FILE *fp;
int i=1;
fp = fopen("intfile.txt","wb");
//printf("Type Number You wnat to ADD to file ");
//scanf("%d",&i);
if(fp){

     while(i<=6){
     fwrite(&i,sizeof(int),1,fp);
      i++;
     }

}else{
  printf("Error while writing in file");
}

fclose(fp);

}

void readadd(){
FILE *fp;
int i,j;
int k=0;
int arr[6];
fp=fopen("intfile.txt","rb");

if(fp){
 for(j=0; j<6;j++){
    fread(&i, sizeof(int),1,fp);
    printf("%d",*(&i));
   arr[k]=*(&i);
   k++;
  }
}else{
printf("Error cannot read from file");
}
int result=0;
int  l;
for(l = 0; l<6; l++){
result = result + arr[l];
printf("\n %d",arr[l]);
}

printf("\n Sum of Elements is:  %d",result); 
fclose(fp);
}

int  main(){
 WriteInFile();
 readadd();
 return 0;
}
