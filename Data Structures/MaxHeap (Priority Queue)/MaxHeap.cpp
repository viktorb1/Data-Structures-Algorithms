#include "MaxHeap.h"

#include <iostream>

using namespace std;

MaxHeap::MaxHeap(int size) : heap_size(0), array_size(size) {
	heap = new int[size];
}


MaxHeap::MaxHeap(int *data, int array_length)
: heap_size(array_length)
, array_size(array_length*2)
{

	if (array_length > 0) {
		heap = new int[array_size];
		
		for (int i = 0; i < array_length; i++)
			heap[i] = data[i];

		for (int i = array_length / 2 - 1; i >= 0; i--)
			percolate_down(i);
	} else {
		heap = new int[1];
		array_size = 1;
		heap_size = 0;
	}

}

MaxHeap::~MaxHeap() {
	delete[] heap;
}


int MaxHeap::left(int i) {
	return 2*i + 1;
}


int MaxHeap::right(int i) {
	return 2*i + 2;
}


int MaxHeap::parent(int i) {
	return (i-1)/2;
}


int MaxHeap::getMax() {
	return heap[0];
}


int MaxHeap::extractMax() {
	return remove(0);
}


void MaxHeap::increaseKey(int i, int increase_by) {
	heap[i] += increase_by;
	percolate_up(i);
}


void MaxHeap::decreaseKey(int i, int decrease_by) {
	heap[i] -= decrease_by;
	percolate_down(i);
}


void MaxHeap::insert(int key) {
	if (heap_size == array_size)
		resize();

	heap[heap_size] = key;
	percolate_up(heap_size++);
}


void MaxHeap::resize() {
	int* old = heap;

	heap = new int[array_size * 2];
	array_size *= 2;

	for (int i = 0; i < heap_size; i++) {
		heap[i] = old[i];
	}

	delete[] old;
}


int MaxHeap::remove(int i) {
	int deletedValue = -1;

	if(i < heap_size && i >= 0) {
		deletedValue = heap[i];
		heap[i] = heap[heap_size-1];
		heap_size--;
		percolate_down(i);
	}

	return deletedValue;
}


void MaxHeap::percolate_up(int i) {
	while (i > 0 && heap[i] > heap[parent(i)]) {
		swap(heap[i], heap[parent(i)]);
		i = parent(i);
	}
}


void MaxHeap::percolate_down(int i) {
	int l = left(i);
	int r = right(i);
	int largest = i;

	if(l < heap_size && heap[l] > heap[i])
		largest = l;

	if (r < heap_size && heap[r] > heap[largest])
		largest = r;

	if (largest != i) {
		swap(heap[i], heap[largest]);
		percolate_down(largest);
	}
}



void MaxHeap::printHeap() {
	int max_for_line = 1, j = 0;

	cout << "Tree: \n";

	for (int i = 0; i < heap_size; i++) {
		cout << heap[i] << " ";
		j++;

		if (j == max_for_line)
		{
			max_for_line *= 2;
			j = 0;
			cout << '\n';
		}

	}

	cout << '\n' << endl;
}