//sicily2038子串翻转

#include <stdio.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <list>
using namespace std;


int main() {
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		int i = 0;
		while (i < s.length()) {
			int j = s.find("_", i);
			if (j < 0) {
				reverse(s.begin() + i, s.end());
				break;
			} else {
				reverse(s.begin() + i, s.begin() + j);
			}
			i = j + 1;
		}
		cout << s << endl;
	}


	//system("pause");
	return 0;
}