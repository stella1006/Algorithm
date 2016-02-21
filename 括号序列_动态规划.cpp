/*
Brackets Sequence
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 28861		Accepted: 8203		Special Judge
Description

Let us define a regular brackets sequence in the following way: 

1. Empty sequence is a regular sequence. 
2. If S is a regular sequence, then (S) and [S] are both regular sequences. 
3. If A and B are regular sequences, then AB is a regular sequence. 

For example, all of the following sequences of characters are regular brackets sequences: 

(), [], (()), ([]), ()[], ()[()] 

And all of the following character sequences are not: 

(, [, ), )(, ([)], ([(] 

Some sequence of characters '(', ')', '[', and ']' is given. You are to find the shortest possible regular brackets sequence, that contains the given character sequence as a subsequence. Here, a string a1 a2 ... an is called a subsequence of the string b1 b2 ... bm, if there exist such indices 1 = i1 < i2 < ... < in = m, that aj = bij for all 1 = j = n.
Input

The input file contains at most 100 brackets (characters '(', ')', '[' and ']') that are situated on a single line without any other characters among them.
Output

Write to the output file a single line that contains some regular brackets sequence that has the minimal possible length and contains the given sequence as a subsequence.
Sample Input

([(]
Sample Output

()[()]
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
#define LL long long
#define lowbit(x) x & (-x)
int d[100][100];
int c[100][100] = {-1};
string s;
int len;

void dp() {
	
	int min ;
	for (int i = 0; i < len; i++) d[i][i] = 1;

	for (int m = 1; m < len; m++) {
		for (int i = 0; i + m < len; i++) {
			int j = i + m;
			min = d[i][i] + d[i+1][j];
			c[i][j] = i;

			for (int k = i + 1; k < j; k++) {
				if (d[i][k] + d[k+1][j] < min) {
					min = d[i][k] + d[k+1][j];
					c[i][j] = k;
				}

			}
			d[i][j] = min;

			if (s[i] == '(' && s[j] == ')' || s[i] == '[' && s[j] == ']') {
				if (d[i+1][j-1] < min) {
					d[i][j] = d[i+1][j-1];
					c[i][j] = -1;
				}

			}

		}
		

	}

}

void print(int x, int y) {
	if (x > y) return;
	if (x == y) {
		if (s[x] == '(' || s[x] == ')') cout << "()";
		else cout << "[]";
	} else {
		if (c[x][y] >= 0) {
			print(x, c[x][y]);
			print(c[x][y] + 1, y);
		} else {
			if (s[x] == '(') {
				cout << "(";
				print(x+1, y - 1);
				cout << ")";
			} else {
				cout << "[";
				print(x+1, y - 1);
				cout << "]";
			}


		}


	}


}

int main() {
	//memset(d,0,sizeof(d));
	cin >> s;
	len = s.size();
	dp();
	print(0, len - 1);
	cout << endl;

	//system ("pause");
	return 0;

}
