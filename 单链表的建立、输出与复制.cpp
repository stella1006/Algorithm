//单链表的建立、输出与复制

#include <stdio.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>
#include <cassert>
#include <list>
using namespace std;

template <typename T> 
struct Node {
	T entry;
	Node *next;
	
};


void print(const Node<int> *head) {
	
	while (head != NULL) {
		int ans = head->entry;
		cout << ans << " ";
		head = head->next;
	}
	cout << endl;
}


Node<int> *createList() {
	int a;
	cin >> a;
	if(a == -1) return 0;
	Node<int> *p = new Node<int>;
	Node<int> *pp = p;
	p->entry = a;
	p->next = NULL;
	while(cin >> a && a != -1) {
		Node<int> *p1 = new Node<int>;
		p1->entry = a;
		p1->next = NULL;
		p->next = p1;
		p = p1;
		
	}
	return pp;

}


Node<int> * copyList(const Node<int> *head) {
	Node<int> *p = new Node<int>;
	p->entry = head->entry;
	p->next = head->next;
	Node<int> *pp = p;
	while ((head = head->next) != NULL) {
		Node<int> *p1 = new Node<int>;
		p1->entry = head->entry;
		p1->next = head->next;
		pp->next = p1;
		pp = p1;
	}

	return p;
}

int main() {
	Node<int> *head = createList();
	print(head);
	Node<int> *h = copyList(head);
	print(h);

	system("pause");
	return 0;
}