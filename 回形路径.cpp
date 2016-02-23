#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#define LL long long
#define ULL unsigned long long 
#define INF 1<<30 
#define Mod 1000000007
#define PII pair<int,int>
#define mk make_pair
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a<b?b:a)
using namespace std;
const double PI=acos(-1.0);
const double EPS=1e-12;
int save[101][101];


int main()
{
	memset(save, 0, sizeof(save));
	int n, m;
	int a, b, c, d;
	cin >> n >> m >> a >> b >> c >> d;
	int ans = 0;

	int p=1,num=0,sum=n*m,flag=0;  //sum为总个数

		while(true)
		{

			//从左向右
			for(int j=p;j<=m-p;j++)
			{
				num++;
				save[p][j]=num;
				if(num==sum) //结束
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;

			//从上向下
			for(int i=p;i<=n-p;i++)
			{
				num++;
				save[i][m-p+1]=num;
				if(num==sum)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;

			//从右向左
			for(int j=m-p+1;j>p;j--)
			{
				num++;
				save[n-p+1][j]=num;
				if(num==sum)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;

			//从下向上
			for(int i=n-p+1;i>p;i--)
			{
				num++;
				save[i][p]=num;
				if(num==sum)
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
			p++;
		}
		for(int i=1;i<=n;i++)
		{
			printf("%2d",save[i][1]);
			for(int j=2;j<=m;j++)
				printf("%3d",save[i][j]);
			putchar('\n');
		}



	//cout << abs(save[a][b] - save[c][d]) << endl;
	//system("pause");
	return 0;
}