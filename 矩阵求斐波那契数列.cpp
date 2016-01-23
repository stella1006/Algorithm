#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define Nnum 31
#define Mnum 31
#define LL long long
struct matrix
{
	int mat[3][3];
	matrix()
	{
		memset(mat,0,sizeof(mat));
	}
};

int m;
matrix mul(matrix A,matrix B)
{
	matrix C;
	int i,j,k;
	for(i=1; i<=2; i++)
	{
		for(j=1; j<=2; j++)
		{
			for(k=1; k<=2; k++)
			{
				C.mat[i][j]=(C.mat[i][j]+A.mat[i][k]*B.mat[k][j])%m;
			}
		}
	}
	return C;
}
matrix powmul(matrix A,int k)
{
	matrix B;
	B.mat[1][1]=B.mat[2][2]=1;
	while(k>=1)
	{
		if(k&1)B=mul(B,A);
		A=mul(A,A);
		k=k/2;
	}
	return B;
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n >> m;
		matrix A;
   
		A.mat[1][1]=A.mat[1][2]=A.mat[2][1]=1;
		A.mat[2][2]=0;
		A=powmul(A,n);
		cout<<A.mat[1][2]<<endl;
	
   
	}
	 return 0;
}
