#include <iostream>
using namespace std;

void printArray(int *nums, int size);
void counting_sort(int* nums, int size);


int main() {
	const int size = 10;
	int nums[size] = {0, 2, 2, 9, 3, 12, 3, 5, 1, 2};

	printArray(nums, size);
	counting_sort(nums, size);
	printArray(nums, size);
}

void counting_sort(int* nums, int size) {
	const int range = 20;
	int counts[range] = {0};
	int sorted[size];

	for (int i = 0; i < size; i++)
		counts[nums[i]]++;

	for (int i = 1; i < range; i++)
		counts[i] += counts[i-1];

	for (int i = size-1; i >= 0; i--) {
		sorted[counts[nums[i]]-1] = nums[i];
		counts[nums[i]]--;
	}

	for (int i = 0; i < size; i++)
		nums[i] = sorted[i];
}


void printArray(int* nums, int size) {
	cout << "Array: ";

	for (int i = 0; i < size; i++)
		if (i < size - 1)
			cout << nums[i] << ", ";
		else
			cout << nums[i] << endl;
}
