//后最表达式

#include <stdio.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <list>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;



int main() {
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		queue<pair<int, int>> q;
		int p[10] = {0};
		int k;
		for (int i = 0; i < n; i++) {
			cin >> k;
			q.push(pair<int, int>(k, i));
			p[k]++;
		}
		k = 9;
		int min = 0;
		while ((q.front()).second != m || (q.front().first != k)) {
			if (p[k] == 0) {
				k--;
			} else if (q.front().first == k) {
				min++;
				p[k]--;
				q.pop();
			} else {
				q.push(q.front());
				q.pop();
			}


		}
		cout << min  + 1 << endl;


	}
	//system("pause");
	return 0;
}