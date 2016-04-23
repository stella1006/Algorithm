#include <iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;


struct p {
	int a;
	int b;
};


p s[1001];
vector<p> v; 

bool operator < (const p& x, const p& y)
{
	return x.b < y.b;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		v.clear();
		memset(s, 0, sizeof(s));
		printf("%s","Case #");
		printf("%d: ", t);
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			s[i].a = i;
			scanf("%d", &(s[i].b));
		}
		sort(s + 1, s + n + 1);

			bool yes = true;
			for (int i = 1; i <= n; i++ ) {
				if (i - 1 < s[i].b) { //
					
					printf("%s\n","No");
					yes = false;
					break;
				}
			}
			if(yes) {
				
				printf("%s\n","Yes");

				for (int i = 2; i <= n; i++) {
					for (int j = 1; j <= s[i].b; j++) {
						p temp;
						temp.a = s[i].a;
						temp.b = s[j].a;
						v.push_back(temp);
						
					}

				}

				printf("%d\n",v.size());
				for (int i = 0; i < v.size(); i++) {
					printf("%d\ ",v[i].a);
					printf("%d\n",v[i].b);
				}
			


		}
	}


	system("pause");
	return 0;
}
