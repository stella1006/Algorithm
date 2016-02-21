#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stack>
#include <cstdio>
#include <unordered_map>
using namespace std;
int num[102][102];



int main() {
	int N;
	scanf("%d", &N);
	memset(num, 0, sizeof(num));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &num[i][j]);
		}
	}

	int r = 1, c = 1;
	while (r <= N) {
		printf("%d ", num[r][c]);
		if (c + 1 <= N && c + 1 >= 1 && r - 1 >= 1 && r - 1 <= N) {
			c++;
			r--;
		} else {
			r = c + 1;
			c = 1;
		}
	}
	r = N;
	c = 2;
	while (c <= N) {
		if (num[r][c] != N * N)
			printf("%d ", num[r][c]);
		else 
			printf("%d\n", num[r][c]);

		if (c + 1 <= N && c + 1 >= 1 && r - 1 >= 1 && r - 1 <= N) {
			c++;
			r--;
		} else {
			c = r + 1;
			r = N;
		}

	}


	//system("pause");
	return 0;
}