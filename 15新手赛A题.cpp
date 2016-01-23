#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[10001];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		memset(a, 0, sizeof(a));

		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];

		if (n < 3) {
			cout << "NO" << endl;
			continue;
		}
		sort(a+1, a + n + 1);
		bool same = false;
		int sum = 0;

		for (int i = 1; i <= n - 1; i++) {
			sum += a[i];
			if (a[i] == a[i+1]) {
				same = true;
				break;
			}
		}
		if(same) {
			cout << "NO" << endl;
			continue;
		} else if (sum <= a[n]) cout << "NO" << endl;
		else cout << "YES" << endl;
	}


	//system("pause");
	return 0;
}
