//多项式的表示和运算
//实现多项式的加法运算。假设多项式均使用降幂排序

#include <stdio.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <list>
using namespace std;
typedef pair<int, int> term;
typedef list<term> polynomial;

polynomial operator + (const polynomial &p, const polynomial &q) {
	polynomial::const_iterator itP, itQ;
	polynomial C;
	itP = p.begin();
	itQ = q.begin();
	while(itP != p.end() && itQ != q.end()) {
		if ((*itP).second == (*itQ).second) {
			term ans(((*itP).first + (*itQ).first), (*itQ).second);
			if (((*itP).first + (*itQ).first) != 0) 
				C.push_back(ans);
			itP++;
			itQ++;
			
		} else if ((*itP).second < (*itQ).second) {
			C.push_back(*itQ);
			itQ++;
		} else {
			C.push_back(*itP);
			itP++;
		}
	}
	while (itP != p.end()) {
		C.push_back(*itP);
		itP++;
	}
	while (itQ != q.end()) {
		C.push_back(*itQ);
		itQ++;
	}


	return C;

}




int main() {
	polynomial A, B;
	int a, b;
	for (int i = 0; i < 4; i++) {
		cin >> a >> b;
		term an(a, b);
		A.push_back(an);
	}
	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		term an2(a, b);
		B.push_back(an2);
	}
	polynomial AplusB = A + B;
	for (polynomial::iterator i = AplusB.begin(); i != AplusB.end(); i++) {
		cout << "(" << (*i).first << "," << (*i).second << ") ";

	}
	cout << endl;






	system("pause");
	return 0;
}