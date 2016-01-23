#include <stdio.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;



string trans(string &s) {
	int len = s.length();
	string str;
	for (int i = 0; i < len; i++) {
		str.push_back(tolower(s[i]));
	}
	return str;
}

int main() {
		int n;
		while(cin >> n && n != 0) {
		string temp;
		int m;
		cin >> m;
		set<string> nV, mV;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			nV.insert(trans(temp));
		}

		for (int i = 0; i < m; i++) {
			cin >> temp;
			
			set<string>::iterator jj = nV.find(trans(temp));
			if (jj != nV.end())
				nV.erase(jj);
			
		}

		cout << nV.size() << endl;
		}

	//system("pause");
	return 0;
}