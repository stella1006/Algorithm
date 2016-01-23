#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
int countPrimes(int n) {
		
		if (n == 2 || n == 0 || n == 1) return 0;
		int count = 0;
		bool *num = new bool[n+1];
		memset(num, 1, sizeof(num));
		for (int i = 2; i*i <= n; i++ ) {
			if (num[i]) {
				for (int j = i; j <= n/i; j++) {
					num[i*j] = 0;
					
				}
			}
		}
		for (int i = 2; i < n; i++) {
			if (num[i])  {
				count++;
				cout << i << endl;
			}
			
		}
		
		return count;
	}

int main() {
	int T;
	cin >> T;
	cout << countPrimes(T) << endl;


	system("pause");
	return 0;
}             