#include<iostream>
using namespace std;

int main()
{
	int matrix1[2][3] = {{1,1,1},{2,2,2}};
	int matrix2[2][3] = {{2,2,2},{3,3,3}};
	int result[2][3];

for(int i=0; i<2;i++)
{
	for(int j=0;j<3;j++)
	{
	result[i][j] = matrix1[i][j] + matrix2[i][j];
	cout<<" "<<result[i][j];
	}
cout<<endl;
}
return 0;
}

 3 3 3
 5 5 5

