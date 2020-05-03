#pragma once
#include <vector>
#include <string>
using namespace std;
template<class T>
class BinaryTree {
private:
	struct Node {

		Node* left;
		Node* right;
		T value;
		Node(T _value) :value(_value), left(nullptr), right(nullptr) {}
	};
	Node* root;
public:
	~BinaryTree() {};
	BinaryTree<T>* Create(T, BinaryTree<T>*, BinaryTree<T>);
	void Order(Node*, vector<T>&);
	vector<T> Order();
	void Insert(T, Node*&);
	void Insert(T);
	void Delete(T, Node*&);
	void Delete(T);
	void dispose(Node*);
	bool SearchNode(T, Node*);
	bool SearchNode(T);
	void leafList(Node*, vector<T>&);
	vector<T> leafListFunc();
	vector<T> Print();
	void FreeTree(BinaryTree<T>*);
	string PrintTree(Node*);
	operator string();
};
template<class T>
BinaryTree<T>* Create(T val, BinaryTree<T>* l = NULL, BinaryTree<T>* r = NULL) {
	BinaryTree<T>* tree;
	tree = new BinaryTree<T>(val, l, r);
	if (tree == NULL) {
		cout << "Error" << endl;
		return;
	}
	return tree;
}

template <class T>
vector<T> BinaryTree<T>::Order() {
	vector<T> ord;
	Order(this->root, ord);
	return ord;
}
template <class T>
void BinaryTree<T>::Order(Node* root, vector<T>& v) {
	if (root != NULL) {
		Order(root->left, v);
		v.push_back(root->value);
		Order(root->right, v);
	}
}
template<class T>
bool BinaryTree<T>::SearchNode(T value) {
	return SearchNode(value, root);
}
template <class T>
bool BinaryTree<T>::SearchNode(T value, Node* root) {
	if (root == NULL) return false;
	else if (root->value == value) return true;
	else if (value < root->value) return SearchNode(value, root->left);
	else if (value > root->value) return SearchNode(value, root->right);
	else return SearchNode(value, root->left);
}
template <class T>
void BinaryTree<T>::Insert(T value) {
	if (root != NULL) this->Insert(value, root);
	else root = new Node(value);
}
template <class T>
void BinaryTree<T>::Insert(T value, Node*& leaf) {
	if (leaf == NULL) leaf = new Node(value);
	else if (value < leaf->value) Insert(value, leaf->left);
	else if (value > leaf->value) Insert(value, leaf->right);
}
template <class T>
void FreeTree(BinaryTree<T>* tree) {
	delete tree;
}
template <class T>
void BinaryTree<T>::Delete(T value) {
	this->Delete(value, root);
}
template <class T>
void BinaryTree<T>::Delete(T value, Node*& root) {
	if (value < root->value) Delete(value, root->left);
	else if (value > root->value) Delete(value, root->right);
	else {
	Node* t = root;
	if (t->right != NULL && t->left == NULL) root = t->right;
	else if (t->left != NULL && t->right == NULL) root = t->left;
	else if (t->left == NULL && t->right == NULL) root = NULL;
	}
}
template<class T>
vector<T> BinaryTree<T>::leafListFunc() {
	vector<T> v;
	leafList(this->root, v);
	return v;
}
template<class T>
void BinaryTree<T>::leafList(Node* root, vector<T>& v) {
	if (root->left == nullptr && root->right == nullptr) v.push_back(root->value);
	else {
		if (root->left) leafList(root->left, v);
		if (root->right) leafList(root->right, v);
	}
}
template <class T>
string BinaryTree<T>::PrintTree(Node* part) {
	string res1, res2;
	if (part->left == NULL) res1 = "";
	else res1 = PrintTree(part->right);
	if (part->right == NULL) res2 = "";
	else res2 = PrintTree(part->right);
	string sum = to_string(part->value) + ' ' + res1 + " " + res2;
	return sum;
}
template <class T>
BinaryTree<T>::operator string() {
		if (root == NULL) return "";
		else return this->PrintTree(this->root);
}

