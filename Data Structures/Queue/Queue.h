#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <list>
using namespace std;

template <typename T>
class Queue {
public:
	list<T> data;
	void push(const T& val);
	T pop();
	bool isEmpty();
};

#include "Queue.cpp"

#endif