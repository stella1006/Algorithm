#include <iostream>
#include <cstring>
using namespace std;
int c[1000001];
int bank[1000001];

int main() {
	int N, p;
	while(cin >> N) {
	
	int color = 1;
	int count = 0;
	
	
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= N; i++) {
		cin >> bank[i];
		if (bank[i] == i) {
			
			count++;
			c[i] = color++;
		}
	}
	
	for (int i = 1; i<= N; i++) {
		if (c[i] == 0) {
			color++;
			p = i;
			
			while(c[p] == 0 ) {
				c[p] = color;
				p = bank[p];
				if (c[p] == color) {
					count++;
					
				}
			}
			



		}

	}

	cout << count << endl;
	}
	system("pause");
	return 0;
}
