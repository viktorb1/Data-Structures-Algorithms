#ifndef _STACK_H_
#define _STACK_H_

using namespace std;

#include <list>

template <typename T>
class Stack {
	list<T> data;

public:
	void push(const T& num);
	T pop();
};

#include "Stack.cpp"

#endif