//设计一个求集合并的函数
//假定一个整数集合用有序序列表示。例如，A={13,5,3,7,9}用有序序列（3,5,7,9,13）表示。
//typedef list<int> set; 
//set setUion(const set &A, const set &B); 返回集合A与B的并集

#include <stdio.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <list>
using namespace std;
typedef list<int> set;

set setUion(const set &A, const set &B){
	set C;
	set::const_iterator itA, itB;
	itA = A.begin();
	itB = B.begin();
	while(itA != A.end() && itB != B.end()) {
		if (*itA <= *itB) {
			C.push_back(*itA);
			itA++;
		} else {
			C.push_back(*itB);
			itB++;
		}
	}
	while (itA != A.end()) {
		C.push_back(*itA);
		itA++;
	} 
	while (itB != B.end()) {
		C.push_back(*itB);
		itB++;
	}

	set::iterator i, j, k;
	for (i = C.begin(); i != C.end(); i++) {
		j = i;
		j++;
		
		while (j != C.end()) {
			k = j;
			j++;
			if (*k == *i){
				C.erase(k);
			}
			
		}
		

	}

	return C;


}

int main() {
	set A, B;
	int ans;
	for (int i = 0 ; i < 5; i++) {
		cin >> ans;
		A.push_back(ans);
	}
	for (int i = 0; i < 6; i++) {
		cin >> ans;
		B.push_back(ans);
	}
	A.sort();
	B.sort();

	set C = setUion(A, B);
	for (set::iterator i = C.begin(); i != C.end(); i++) {
		cout << *i << " " ;
	}
	cout << endl;



	system("pause");
	return 0;
}