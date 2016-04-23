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

void level_traverse(BinaryNode* root) {
	BinaryNode* sub_root;
	if (root != NULL) {
		queue<BinaryNode* > waiting_nodes;
		waiting_nodes.push(root);
		do {
			sub_root = waiting_nodes.front();
			cout << sub_root->elements;
			if (sub_root->left) waiting_nodes.push(sub_root->left);
			if (sub_root->right) waiting_nodes.push(sub_root->right);
			waitin_nodes.pop(); 
		} while (!waiting_nodes.empty());
	}
}
