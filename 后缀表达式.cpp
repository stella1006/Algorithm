//后缀表达式

#include <stdio.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <list>
#include <stack>
#include <iomanip>
using namespace std;

int ltoi(char a) {
	return a - 'a' + 1;
}


int main() {
	int n;
	cin >> n;
	while (n--) {
		stack<double> r;
		string s;
		cin >> s;
		double result;
		char c;
		for (int i = 0; i < s.length(); i++) {
			c = s[i];
			if (c >= 'a' && c <= 'z') {
				r.push(ltoi(c));
			} else if (c == '-') {
				double a = r.top();
				r.pop();
				double b = r.top();
				r.pop();
				double c = b - a;
				r.push(c);
			} else if (c == '+') {
				double a = r.top();
				r.pop();
				double b = r.top();
				r.pop();
				double c = b + a;
				r.push(c);
			} else if (c == '*') {
				double a = r.top();
				r.pop();
				double b = r.top();
				r.pop();
				double c = 1.0 * b * a;
				r.push(c);
			} else {
				double a = r.top();
				r.pop();
				double b = r.top();
				r.pop();
				double c = 1.0 * b / a;
				r.push(c);
			}

			
		}
		result = r.top(); 
		cout << setprecision(2) << std::fixed <<  result << endl;

		

	}

	
	
	

	//system("pause");
	return 0;
}