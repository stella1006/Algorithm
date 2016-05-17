#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include<functional>
using namespace std;

class Graph {
public:
	vector<list<int> > neighbour;
	vector<int> indegree;
	int vexNum;
	int acrNum;
};
//template <typename T>
//class greater {
//public:
//	bool operator() (const T a, const T b) {
//		return a > b;
//	}
//};
vector<int> topologicalSorting(Graph g) {
	priority_queue<int, vector<int>, greater<int> > q;
	vector<int> ordering;
	for (int i = 1; i <= g.vexNum; i++) 
		if (g.indegree[i] == 0) q.push(i);
	
	while (!q.empty()) {
		int v = q.top();
		q.pop();
		ordering.push_back(v);
		list<int>::iterator it = g.neighbour[v].begin();
		while (it != g.neighbour[v].end()) {
			g.indegree[*it]--;
			if (g.indegree[*it] == 0) q.push(*it);
			it++;
		}
	}
	return ordering;
}

Graph makeGraph() {
	Graph g;
	cin >> g.vexNum;
	cin >> g.acrNum; 
	g.neighbour.resize(g.vexNum + 1);
	g.indegree.resize(g.vexNum + 1);
	int v, w;
	for (int i = 0; i < g.acrNum; i++) {
		cin >> v >> w;
		g.neighbour[v].push_back(w);
		g.indegree[w]++;
	}
	return g;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		Graph g;
		g = makeGraph();
		vector<int> res = topologicalSorting(g);
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
