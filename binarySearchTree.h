#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <queue>
#include <stack>
using namespace std;


template <typename T>
struct treeNode {
	T data;
	struct treeNode<T> *left, *right;
	treeNode(T d, treeNode *l = NULL, treeNode *r = NULL) : data(d), left(l), right(r) {};
};

template <typename T> 
class BinTree {
public:
	BinTree() {root = NULL;};          //Construct a empty binary tree
	BinTree(T d) {root = new T(d);};   //Construct a binary tree with single node
	BinTree(const BinTree& original);   //copy constructor
	BinTree & operator = (const BinTree<T> &original);   //override = operator
	~BinTree();   //destructor
	bool insert(const T d) ;       //insert data d, if succeed, return true and return false otherwise
	bool search(const T d) const;       //find d. Return true if succeed
	void print() ;        //level traverse
	void traversal(void (*visit)(T d)) const;   //traverse inorder

private:
	treeNode<T>* root;
	int count;    //number of nodes
	bool insertR(treeNode<T>* & t, const T d); //insert recursivly
	void printR(treeNode<T>* & t) ;
	void levelTraR(treeNode<T>* & t, int level, vector<vector<T>> &res);
	void release(treeNode<T> *t);
	void traversalR(const treeNode<T>*t, void (*visit)(T d)) const;
};


template <typename T> 
bool BinTree<T>::insertR(treeNode<T>* & t, const T d) {
	if (t == NULL) {
		treeNode<T>* temp = new treeNode<T>(d);
		t = temp;
		count++;
		return true;
	}

	if (d < t->data) {
			return insertR(t->left, d);
	} else if (d > t->data) {
		return insertR(t->right, d);
	} else {}
	return false;
}

template <typename T> 
void BinTree<T>::levelTraR(treeNode<T>* & t, int level, vector<vector<T>> &res) {
	if (!t) return;
	if (level > res.size()) {
		res.push_back(vector<int>());
	}
	res[level-1].push_back(t->data);
	levelTraR(t->left, level+1, res);
	levelTraR(t->right, level+1, res);

}

template <typename T> 
void BinTree<T>::printR(treeNode<T>* & t)  {
	vector<vector<T>> res;
	levelTraR(t, 1, res);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	/*queue<treeNode<T>*> q;
	if (t) q.push(t);
	else {
		cout << "empty" << endl;
		return;
	}
	while (!q.empty()) {
		treeNode<T> * temp = q.front();
		q.pop();
		cout << temp->data << " ";
		if (temp->left)
			q.push(temp->left);
		if (temp->right) 
			q.push(temp->right);
	}*/
	cout << endl;
}

template <typename T> 
void BinTree<T>::release(treeNode<T> *t) {
	delete t;
}

template <typename T> 
void BinTree<T>::traversalR(const treeNode<T>*t, void (*visit)(T d)) const {
	if (t != NULL) {
		traversalR(t->left, visit);
		visit(t->data);
		traversalR(t->right, visit);
	}
}

template <typename T> 
BinTree<T>::BinTree(const BinTree& original) {
	this->root = original.root;
	this->count = original.count;
}

template <typename T>
BinTree<T> & BinTree<T>::operator = (const BinTree<T> &original) {
	root = &original->root;
	if (root != NULL) {
		root->left = original->root->left;
		root->right = original->root->right;
	}
	

	return *this;
}

template <typename T>
BinTree<T>::~BinTree() {
	release(root);
}

template <typename T>
bool BinTree<T>::insert(const T d) {
	if (search(d)) return false;
	insertR(root, d);
	return true;
}

template <typename T>
bool BinTree<T>::search(const T d) const{
	treeNode<T>* p = root;
	while (p != NULL) {
		if (d < p->data) {
			p = p->left;
		} else if (d > p->data) {
			p = p->right;
		} else {
			return true;
		}
	}
	return false;
}

template <typename T>
void BinTree<T>::print() {
	printR(root);
}

template <typename T>
void BinTree<T>::traversal(void (*visit)(T d)) const {
	traversalR(root, visit);
	cout << endl;
}

#endif BINARY_SEARCH_TREE.H