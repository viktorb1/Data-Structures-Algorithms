using namespace std;

#include <iostream>
#include <climits>

void printArray(int *nums, int size);
int selection_sort(int* nums, int size);


int main() {
	const int size = 10;
	int nums[size] = {-9, 2, 2, 9, 31, 12, 3, 5, -4, -3};

	printArray(nums, size);
	selection_sort(nums, size);
	printArray(nums, size);
}


int selection_sort(int* nums, int size) {
	for (int i = 0; i < size-1; i++) {
		
		int min_index = i;

		for (int j = i+1; j < size; j++)
			if (nums[j] < nums[min_index])
				min_index = j;

		swap(nums[min_index], nums[i]);
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
