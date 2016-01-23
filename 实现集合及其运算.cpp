//实现集合及其运算

#include <stdio.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <list>

using namespace std;
typedef int set_entry;
typedef list<set_entry> set;

bool element(const set_entry &x, const set &s) {
	if (binary_search(s.begin(), s.end(), x))
		return true;
	else return false;
}

void insert (set &s, const set_entry &x) {
	set::iterator it;
	it = upper_bound(s.begin(), s.end(), x);
	if (!element(x, s)) {
		if (it != s.end()) {
			s.insert(it, x);
		} else {
			s.push_back(x);
		}

	}	
}

void set_union(const set &s, const set &t, set &u) {
	set::const_iterator i, j;
	i = s.begin();
	j = t.begin();
	while (i != s.end() && j != t.end()) {
		if (*i < *j) {
			set_entry temp = *i;
			u.push_back(temp);
			i++;
		} else {
			set_entry temp = *j;
			u.push_back(temp);
			j++;
		}
	}

	while (i != s.end()) {
		set_entry temp = *i;
		u.push_back(temp);
		i++;
	}

	while (j != t.end()) {
		set_entry temp = *j;
		u.push_back(temp);
		j++;
	}
	set::iterator k, m, n;
	for (k = u.begin(); k != u.end(); k++) {
		m = k;
		m++;
		while (m != u.end()) {
			n = m;
			m++;
			if (*n == *k) {
				u.erase(n);
			}
		}
	}
}

void set_intersection(const set &s, const set &t, set &u) {
	set::const_iterator i, j;
	set ans;
	i = s.begin();
	j = t.begin();
	while (i != s.end() && j != t.end()) {
		if (*i < *j) {
			set_entry temp = *i;
			ans.push_back(temp);
			i++;
		} else {
			set_entry temp = *j;
			ans.push_back(temp);
			j++;
		}
	}

	while (i != s.end()) {
		set_entry temp = *i;
		ans.push_back(temp);
		i++;
	}

	while (j != t.end()) {
		set_entry temp = *j;
		ans.push_back(temp);
		j++;
	}

	set::iterator k, m, n;
	for (k = ans.begin(); k != ans.end(); k++) {
		m = k;
		k++;
		while (k != ans.end()) {
			n = k;
			k++;
			if (*n == *k) {
				u.push_back(*n);
				break;
			}

		}

	}

}

bool subset(const set &s, const set &t) {
	set::const_iterator i, j;
	
	for (i = s.begin(); i != s.end(); i++) {
		if (!element(*i, t)) return false;
	}

	return true;
}


int main() {
	set S, S2, U, I;
	insert(S, 1);
	insert(S, 2);
	insert(S, 7);
	insert(S, 6);
	insert(S, 4);
	insert(S2, 4);
	insert(S2, 7);
	set_union(S, S2, U);
	set_intersection(S, S2,I);
	cout << "subset : " << subset(S2, S) << endl;
	cout << "U:" << endl;
	for (set::iterator i = U.begin(); i != U.end(); i++) {
		cout << *i << " " ;
	}
	cout << endl;

	cout << "I: " << endl;
	for (set::iterator i = I.begin(); i != I.end(); i++) {
		cout << *i << " " ;
	}
	cout << endl;


	system("pause");
	return 0;
}