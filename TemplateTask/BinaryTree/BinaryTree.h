#pragma once
#include <vector>
template<class T>
class SearchTree;
template<class T>
class BinaryTree {
private:
	struct Node {
		
		Node *left;
		Node *right;
		T data;
	};
Node *root;
public:
	//T value;
	//BinaryTree(const T& val, BinaryTree<T>* l, BinaryTree<T>* r) : value(val), left(l), right(r) {}
	BinaryTree():root(NULL) {}
	~BinaryTree() {};
	BinaryTree<T>* Create(T, BinaryTree<T>*, BinaryTree<T>);
	void Order(Node*, vector<T>&);
	friend class SearchTree<T*>;*/
	void Insert(T, Node*&);
	void Delete(T, Node*&);
	bool SearchNode(T, Node*);
	void leafList(Node*, vector<T>&);
	vector<T> Print();
	void FreeTree(BinaryTree<T>*);
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
	vector<T> v;
	Order(v, this->root);
	delete root;
}
template <class T>
void BinaryTree<T>:: Order(Node*, vector<T>& v) {
	if (root != NULL) {
		Order(tree->left, v);
		visit(tree->value);
		Order(tree->right, v);
	}
}
template <class T>
bool BinaryTree<T>::SearchNode(T data, Node* root) {
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data < root->data) return SearchNode(data, root->left);
	else if (data > root->data) return SearchNode(data, root->right);
	else return SearchNode(data, root->left);
}

template <class T>
void BinaryTree<T>::Insert(T data, Node*& leaf) {
	if (leaf == NULL) leaf = new Node(data);
	else if (data < leaf->data) Insert(data, leaf->left);
	else if (data > leaf->data) Insert(data, leaf->right);
}
template <class T>
void FreeTree(BinaryTree<T>* tree) {
	delete tree;
}
template <class T>
void BinaryTree<T>::Delete(T data, Node*& root) {
	if (data < root->data) Delete(data, root->left);
	else Delete(data, root->right);
	else {
		Node* t = root;
		if (t->right != NULL && t->left == NULL) root = t->right;
		else if (t->left != NULL && t->right == NULL) root = t->left;
		else if (t->left == NULL && t->right == NULL) root = NULL;
	}
}
template<class T>
void BinaryTree<T>::leafList(Node* root, vector<T>& v) {
	if (tree->left == nullptr && tree->right == nullptr) v.push_back(tree->data);
	else {
		if (tree->left) leafList(tree->left,v);
		if (tree->right) leafList(tree->right,v);
	}
}
template <class T>
void BinaryTree<T>::Print() {
	vector<T> printList;
	leafList(this->root, printList);
	return printList;
}
string BinaryTree<T>::PrintTree(Node *part) {
	string res1, res2;
	if (part->left == NULL) {
		res1 = "";
	}
	else res1 = PrintTree(part->right);
	if (part->right == NULL) {
		res2 = "";
	}
	else res2 = PrintTree(part->right);
	string sum = to_string(part->data) + ' ' + res1 + " " + res2;
	return sum;
}
template <class T>
BinaryTree<T>::operator string() {
	string rez="{"+to_string(this->root->data)+' ' + 
	if (root = NULL) return "";
	else return this->PrintTree(this->root);
}

