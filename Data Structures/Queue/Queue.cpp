#include "Queue.h"
#include <stdexcept>

template <typename T>
void Queue<T>::push(const T& val) {
	data.push_back(val);
}


template <typename T>
T Queue<T>::pop() {
	if (data.empty())
		throw std::out_of_range("Queue underflow error.");

	T front = data.front();
	data.pop_front();

	return front;
}

template <typename T>
bool Queue<T>::isEmpty() {
	return data.empty();
}