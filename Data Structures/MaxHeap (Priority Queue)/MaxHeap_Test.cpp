#include "MaxHeap.h"

using namespace std;

#include <iostream>

int main() {
	int array[6] = {4,2,5,8,1,3};
	MaxHeap m(array, 6);
	m.printHeap();
	m.insert(9);
	m.insert(6);
	m.insert(12);
	m.insert(15);
	m.insert(19);
	m.insert(23);
	m.insert(24);
	m.printHeap();
	m.increaseKey(0, 4);
	m.printHeap();
	m.decreaseKey(0, 8);
	m.printHeap();
	m.increaseKey(6, 95);
	m.printHeap();
	m.extractMax();
	m.printHeap();
	m.remove(5);
	m.printHeap();

	return 0;
}