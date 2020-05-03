#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;
int main() {
	BinaryTree<int> tree;
	tree.Insert(7);
	tree.Insert(11);
	tree.Insert(15);
	cout << (string)tree << endl;
	tree.Delete(11);
	cout << tree.SearchNode(7) << endl;
	tree.Delete(15);
	cout << (string)tree << endl;
	tree.Insert(9);
	tree.Insert(17);
	vector<int> leafList = tree.leafListFunc();
	for (int i = 0; i < leafList.size(); i++) cout << leafList[i] << " ";
	cout << endl;
	vector<int> ord = tree.Order();
	for (int i = 0; i < ord.size(); i++) cout << ord[i] << " ";
}