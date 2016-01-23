#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[102];
int b[102];

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		
		memset(a, 0, sizeof(a));
		for (int i = 0; i < 102; i++) {
			b[i] = 1;
		}
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			
		}
		bool flag = false;
		while(!flag){
			flag = true;
			for (int i = 0; i < n; i++) {
				if (n == 1) {
					break;
				}

				if (i == 0) {
					if (a[0] > a[1] && a[0] > a[n-1]) {
						if (b[1] > b[n-1] && b[0] <= b[1]) {
							b[0] = b[1] + 1;
							flag = false;
						
						} else if(b[0] <= b[n-1]){
							b[0] = b[n-1] + 1;
							flag = false;
						
						}
					} else if (a[0] > a[n-1] && b[0] <= b[n-1]) {
						b[0] = b[n-1] + 1;
						flag = false;
						
					} else if (a[0] > a[1] && b[0] <= b[1]) {
						b[0] = b[1] + 1;
						flag = false;
						
					}

				}
				 else if (i == n-1) {
					if (a[n-1] > a[n-2] && a[n-1] > a[0]) {
						if (b[n-2] > b[0] && b[n-1] <= b[n-2]) {
							b[n-1] = b[n-2] + 1;
							flag = false;
							
						} else if(b[n-1] <= b[0]){
							b[n-1] = b[0] + 1;
							flag = false;
						
						}
					} else if (a[n-1] > a[n-2] && b[n-1] <= b[n-2]) {
						b[n-1] = b[n-2] + 1;
						flag = false;
						
					} else if(a[n-1] > a[0] && b[n-1] <= b[0]) {
						b[n-1] = b[0] + 1;
						flag = false;
						
					}
				}
				 else if (i > 0 && i < n - 1){
					if (a[i] > a[i-1] && a[i] > a[i+1]) {
						if (b[i-1] > b[i+1] && b[i] <= b[i-1] ) {
							b[i] = b[i-1] + 1;
							flag = false;
						} else if (b[i] <= b[i+1]){
							b[i] = b[i+1] + 1;
							flag = false;
						}
					} else if (a[i] > a[i-1] && b[i] <= b[i-1]) {
						b[i] = b[i-1] + 1;
						flag = false;	
					} else if (a[i] > a[i+1] && b[i] <= b[i+1]) {
						b[i] = b[i+1] + 1;
						flag = false;
						
					}
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			//cout << b[i] << endl;
			sum += b[i];
		}
		cout << "Case #" << t << ": " << sum << endl;



	}


	//system("pause");
	return 0;
}
