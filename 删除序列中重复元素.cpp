//删除重复元素
//现将序列排序，然后在扫描有序序列的过程中删除重复元素的出现。算法时间复杂度为O(nlogn)

#include <stdio.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <set>
using namespace std;


int main() {
		vector<int> V;
		vector<int>::iterator k, j;
		int ans;
		for(int i = 0; i < 5; i++) {
			cin >> ans;
			V.push_back(ans);
		}
		sort(V.begin(), V.end());
		for (k = V.begin(); k != V.end() - 1;) {
			j = k + 1;
			bool flag = false;
			while(*j == *k && j != V.end()) {
				flag = true;
				j = V.erase(j);	
			}
			k++;

		}

		for (int i = 0; i < V.size(); i++) {
			cout << V[i] << " ";
			if (i == V.size() - 1) 
				cout << endl;
		}



	system("pause");
	return 0;
}