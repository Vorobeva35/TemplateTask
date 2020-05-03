// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include "BinaryTree.h"
using namespace std;


int main()
{
	BinaryTree<int> tree;
	vector<int>v = tree.Order();
	tree.Insert(7);
	tree.Insert(11);
	tree.Insert(15);
	tree.Insert(2);
	cout << (string)tree << endl;
	tree.Delete(2);
	tree.SearchNode(7);
	tree.Delete(15);
	cout << (string)tree << endl;
	tree.Insert(9);
	tree.Insert(17);
	vector<int> leafList = tree.leafList();
	for (int i = 0; i < leafList.size(); i++) cout << leafList[i] << endl;
	vector<int> ord = tree.Order();
	for (int i = 0; i < ord.size(); i++) cout << ord[i] << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
