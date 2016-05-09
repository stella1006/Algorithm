#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#define LL long long
#define ULL unsigned long long 
#define INF 1<<30 
#define Mod 1000000007
#define PII pair<int,int>
#define mk make_pair
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a<b?b:a)
using namespace std;

struct BinaryNode {
	int elements;
	BinaryNode* left;
	BinaryNode* right;
};

void nonRecursiveInorder(BinaryNode* root) {
	stack<BinaryNode* > s;
	BinaryNode* p = root;
	while (p || !s.empty()) {
		if (p) {
			s.push(p);
			p = p->left;
		} else {
			p = s.top();
			s.pop(); 
			cout << p->elements;
			p = p->right;
		}
	}
}

int main() {
	return 0;
}
