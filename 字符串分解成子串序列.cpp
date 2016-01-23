//字符串分解成子串序列

#include <stdio.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <list>
using namespace std;

list<string> getListofWords(string &s) {
	list<string> result;
	char spaces[] = " ,.!?";
	char* cs;
	cs = strtok((char*)(s.c_str()), " ");
	while (cs != NULL) {
		result.push_back(cs);
		cs = strtok(NULL, " ");
		
	}
	return result;

}


int main() {
	string s;
	getline(cin, s, '\n');
	list<string> result = getListofWords(s);
	for (list<string>::iterator i = result.begin(); i != result.end(); i++) {
		cout << *i << endl;
	}
	
	
	
	

	system("pause");
	return 0;
}