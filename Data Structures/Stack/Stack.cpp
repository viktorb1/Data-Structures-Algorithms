#include "Stack.h"
#include <stdexcept>


template <typename T>
void Stack<T>::push(const T& val) {
	data.push_back(val);
}


template <typename T>
T Stack<T>::pop() {

	if (data.empty())
		throw out_of_range("Stack underflow error.");
	
	int top = data.back();
	data.pop_back();
	return top;
}