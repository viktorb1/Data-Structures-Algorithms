using namespace std;

#include <iostream>
#include <climits>

void printArray(int *nums, int size);
int bubble_sort(int* nums, int size);


int main() {
	const int size = 10;
	int nums[size] = {-9, 2, 2, 9, 31, 12, 3, 5, -4, -3};

	printArray(nums, size);
	bubble_sort(nums, size);
	printArray(nums, size);
}


int bubble_sort(int* nums, int size) {
	for(int i = 0; i < size-1; i++)
		for(int j = 0; j < size-i-1; j++)
			if (nums[j] > nums[j+1])
				swap(nums[j], nums[j+1]);
}


void printArray(int* nums, int size) {
	cout << "Array: ";

	for (int i = 0; i < size; i++)
		if (i < size - 1)
			cout << nums[i] << ", ";
		else
			cout << nums[i] << endl;
}
