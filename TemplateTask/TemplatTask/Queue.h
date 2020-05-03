#pragma once
#include <iostream>
using namespace std;
template<class T>
class Queue;
template<class T>
Queue<T> Union(const Queue<T>& q1, const Queue<T>& q2);
template <class T>
class Queue
{
private:
	T* ptr;
	int size;
	int head;
	int tail;
	int count;
public:
	Queue(int);
	Queue(const Queue&);
	~Queue();
	void push(T);
	T pop();
	bool IsEmpty();
	bool IsFull();
	void Print();
	friend Queue Union<T>(const Queue<T>& q1, const Queue<T>& q2);
};
template <class T>
Queue<T>::Queue(int size) {
	this->size = size;
	ptr = new T[size];
	head = 0;
	tail = -1;
	count = 0;
}
template <class T>
Queue<T>::Queue(const Queue& q) {
	this->size = q.size;
	this->ptr = new T[size];
	copy(q.ptr, q.ptr + q.size, this->ptr);
	this->head = q.head;
	this->tail = q.tail;
	this->count = q.count;
}
template <class T>
Queue<T>::~Queue() {
	delete[] ptr;
}

template <class T>
bool Queue<T>::IsFull() {
	if (count == size) return true;
	else return false;
}
template <class T>
void Queue<T>::push(T value) {
	if (!IsFull()) {
		tail++;
		count++;
		ptr[tail] = value;
	}
	else throw new invalid_argument("Queue is Full");
}
template <class T>
bool Queue<T>::IsEmpty() {
	if (head == 0) return true;
	else return false;
}
template <class T>
T Queue<T>::pop() {
	if (!IsEmpty()) {
		head++;
		count--;
		return ptr[head];
	}
	else return new invalid_argument("Queue is Empty");
}
template <class T>
Queue<T> Union(const Queue<T>& q1, const Queue<T>& q2) {
	Queue<T> q3(q1.size + q2.size);
	int countq = 0, ind = q1.head;
	while (countq < q1.count) {
		q3.push(q1.ptr[ind]);
		++countq;
		ind++;
		ind %= q1.size;
	}
	ind = q2.head;
	countq = 0;
	while (countq < q2.count) {
		q3.push(q2.ptr[ind]);
		++countq;
		ind++;
		ind %= q2.size;
	}
	return q3;
}

template<class T>
void Queue<T>::Print()
{
	for (int i = head; i <= tail; i++) {
		cout << ptr[i] << ' ';
	}
	cout << endl;
}


