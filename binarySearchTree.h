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
	void print() const;        //level traverse
	void traversal(void (*visit)(T d)) const;   //traverse inorder

private:
	treeNode<T>* root;
	int count;    //number of nodes
	bool insertR(treeNode<T>* & t, const T d); //insert recursivly
	void printR(const treeNode<T>* t, queue<treeNode<T>*> q) const; //recursively print the tree from the node t with the help of the queue q
	void release(treeNode<T> *t);
	void traversalR(const treeNode<T>*t, void (*visit)(T d)) const;
};

template <typename T> 
BinTree<T>::BinTree(const BinTree& original) {//copy constructor
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
bool BinTree<T>::insertR(treeNode<T>* & t, const T d) {//recursively insert data d into the tree from the node t
	if (t == NULL) {//if the tree is empty
		treeNode<T>* temp = new treeNode<T>(d);
		t = temp;
		count++;
		return true;
	}

	if (d < t->data) {
			return insertR(t->left, d);  //go to left child if any
	} else if (d > t->data) {
		return insertR(t->right, d);  //go to right child if any
	} else {}
	return false;
}

template <typename T> 
void BinTree<T>::printR(const treeNode<T>* t, queue<treeNode<T>*> q) const { //recursively print the tree from the node t with the help of the queue q
		cout << t->data << " ";
		if (t->left != NULL) //push the left child node into the queue if any
			q.push(t->left);
		if (t->right != NULL) //push the right child node into the queue if any
			q.push(t->right);
		if (q.empty())
			return;
		else { //the queue is not empty
			t = q.front();
			q.pop();
			printR(t, q);
		}
	}

template <typename T> 
void BinTree<T>::release(treeNode<T> *t) {   ///release the memory
	delete t;
}

template <typename T> 
void BinTree<T>::traversalR(const treeNode<T>*t, void (*visit)(T d)) const { //recursively traverse the tree from the node t
	if (t != NULL) {
		traversalR(t->left, visit);   //traverse left child node if any
		visit(t->data);
		traversalR(t->right, visit);   //traverse right child node if any
	}
}



template <typename T>
bool BinTree<T>::insert(const T d) {
	if (search(d)) return false;
	insertR(root, d);
	return true;
}

template <typename T>
bool BinTree<T>::search(const T d) const{    //search for data d in the tree
	treeNode<T>* p = root;
	while (p != NULL) { 
		if (d < p->data) {
			p = p->left;   //go to left child node if not any
		} else if (d > p->data) {  
			p = p->right;   //go to right child node if not any
		} else {
			return true;
		}
	}
	return false;
}

template <typename T>
void BinTree<T>::print() const { //print the tree by hierarchy traversal
	if (root != NULL) {
		queue<treeNode<T>*> q; //to store the nodes to visit
		printR(root, q); //recursively print the tree from the root with the help of the queue
	}
	cout << endl;
}

template <typename T>
void BinTree<T>::traversal(void (*visit)(T d)) const {
	traversalR(root, visit);
	cout << endl;
}

#endif BINARY_SEARCH_TREE.H