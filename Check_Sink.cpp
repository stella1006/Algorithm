#include <iostream>
#include <queue>
#define V 4
#define W 4
using namespace std;



bool isContSink(int G[V][W]) {
	int c = 0;
	for (int i = 0; i < W; i++) {
		if (G[c][i]) c = i;
	}

	for (int i = 0; i < W; i++) {
		if (i != c && (G[i][c] == 0 || G[c][i] == 1)) {
			return false;
		}
	}
	return true;
}


int main()
{
	int G[V][W] = {{0, 1, 1, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 0}
	};

	cout << isContSink(G) << endl;

	system ("pause");
	return 0;
	
}
