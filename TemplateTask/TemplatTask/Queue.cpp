#include "Queue.h"
#include <iostream>
using namespace std;


int main() {
	Queue<int> q(3);
	Queue<int> q1(3);
	q.Print();
	q.push(15);
	q.Print();
	q.push(8);
	q.Print();
	q.pop();
	q.Print();
	q1.push(4);
	q1.push(7);
	q1.Print();
	
	Queue<int> q2=Union(q, q1);
	q2.Print();
	return 0;
}