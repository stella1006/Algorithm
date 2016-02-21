#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
#define N 1000000
#define LL long long
#define lowbit(x) x&(-x)
LL tree[N + 10];


void add(int x, int d) {
	while (x) {
		tree[x] += d;
		x -= lowbit(x);
	}

}

LL sum(int x) {
	LL s = 0;
	while (x <= N) {
		s +=tree[x];
		x += lowbit(x);
	}
	return s;

}




int main() {
	char s[20];
	LL res = 0;
	double c;
	int n;

	while(scanf("%s",s)!= EOF) {
		if (s[0] == 'Q') break;
		else if (s[0]=='B') {
			scanf("%lf", &c);
			int ans = floorl(c * 100.0+ 0.5);
			add(ans, 1);
		}  else if (s[0]== 'D') {
			scanf("%lf", &c);
			int ans = floorl(c * 100.0 + 0.5);
			add(ans, -1);
		} else if (s[0]=='S') {
			
			scanf("%lf", &c);
			scanf("%d", &n);
			int ans = floorl(c * 100.0 + 0.5);
			LL ss = sum(ans);
			if (ss >= n) res += n;
			else res += ss;

		}
	}

	cout<<fixed<<setprecision(2)<<0.01*res<<endl;

	//system("pause");
	return 0;
}