#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stdio.h>
using namespace std;
int ROW;
int COL;
#define LL long long
#define INF 1000000
int graph[101][101];
bool flag[101][101];
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};


bool valid(int a, int b, int r, int c) {
	return a >= 0 && a < r && b >= 0 && b < c;
}

struct Path {
	int r, c;
	LL distance;
	Path(int a, int b, int c):r(a), c(b), distance(c){}
	friend bool operator < (const Path & a, const Path & b) {
		return a.distance > b.distance;
	}
};


LL shortestSumPath_Dijkstra(const int G[][101], int row, int column, int s0, int s1, int end0, int end1) { 
	memset(flag, 0, sizeof(flag));
	priority_queue<Path> q;
	flag[s0][s1] = true;
	Path temp = Path(s0, s1, graph[s0][s1]);
	while (!flag[end0][end1]) {
		for (int i = 0; i < 4; i++) {
			int newr, newc;
			newr = temp.r + d[i][0];
			newc = temp.c + d[i][1];
			if (valid(newr, newc, row, column) && !flag[newr][newc]) 
				q.push(Path(newr, newc, temp.distance + graph[newr][newc]));
		}

		temp = q.top();
		if (flag[temp.r][temp.c]) {
			q.pop();
			temp = q.top();
		}
		flag[temp.r][temp.c] = true;
	}
	return temp.distance;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(graph, 0, sizeof(graph));
		
		int row,column, dis;
		scanf("%d%d", &row, &column);
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				scanf("%d", &dis);
				graph[i][j] = dis;
			}
		}
		
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		cout << shortestSumPath_Dijkstra(graph, row, column, a-1, b-1, c-1, d-1) << endl;
	}
	system("pause");
	return 0;
}