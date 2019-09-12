#include "../../Data Structures/MaxHeap (Priority Queue)/MaxHeap.h"
#include <iostream>
using namespace std;

void printArray(int* nums, int size);
void heapSort(MaxHeap& m, int* nums, int size);

int main() {
	int size = 10;
	int nums[size] = {-9, 2, 2, 9, 31, 12, 3, 5, -4, -3};
	MaxHeap m(nums, size);
	heapSort(m, nums, size);
	printArray(nums, size);
}

void heapSort(MaxHeap& m, int* nums, int size) {
	for (int i = 0; i < size; i++)
	{
		nums[size-i-1] = m.extractMax();
	}
}


void printArray(int* nums, int size) {
	cout << "Array: ";

	for (int i = 0; i < size; i++)
		if (i < size - 1)
			cout << nums[i] << ", ";
		else
			cout << nums[i] << endl;
}