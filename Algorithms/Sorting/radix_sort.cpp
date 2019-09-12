using namespace std;

#include <iostream>

void printArray(int *nums, int size);
void radix_sort(int* nums, int size);
void counting_sort(int* nums, int size, int place);

// sorts positive numbers only
int main() {
	const int size = 10;
	int nums[size] = {9, 2, 2, 9, 31, 12, 3, 5, 4, 56};

	printArray(nums, size);
	radix_sort(nums, size);
	printArray(nums, size);
}



void radix_sort(int* nums, int size) {
		
	int max = nums[0];
	for (int i = 0; i < size; i++)
		if (nums[i] > max)
			max = nums[i];

	
	for (int place = 1; place < max; place *= 10)
		counting_sort(nums, size, place);
}


void counting_sort(int* nums, int size, int place) {
	const int range = 10;
	int counts[range] = {0};
	int sorted[size];

	for (int i = 0; i < size; i++)
		counts[(nums[i] / place) % 10]++;

	for (int i = 1; i < range; i++)
		counts[i] += counts[i-1];

	for (int i = size-1; i >= 0; i--) {
		sorted[counts[(nums[i] / place) % 10]-1] = nums[i];
		counts[(nums[i] / place) % 10]--;
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

