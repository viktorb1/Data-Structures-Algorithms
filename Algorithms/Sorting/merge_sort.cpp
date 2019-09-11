using namespace std;

#include <iostream>

void printArray(int *nums, int size);
void merge_sort(int* nums, int p, int r);
void merge(int* nums, int p, int q, int r);


int main() {
	const int size = 10;
	int nums[size] = {-9, 2, 2, 9, 31, 12, 3, 5, -4, -3};

	printArray(nums, size);
	merge_sort(nums, 0, size-1);
	printArray(nums, size);
}


void merge_sort(int* nums, int p, int r) {
	if (p < r) {
		int q = (p+r)/2;
		merge_sort(nums, p, q);
		merge_sort(nums, q+1, r);
		merge(nums, p, q, r);
	}
}

void merge(int* nums, int p, int q, int r) {
	int lsize = q-p+1, rsize = r-q;
	int left[lsize], right[rsize];

	for (int i = 0; i < lsize; i++)
		left[i] = nums[p+i];

	for (int j = 0; j < rsize; j++)
		right[j] = nums[q+j+1];

	int i = 0, j = 0, k = p;

	while (i < lsize && j < rsize) {
		if (left[i] <= right[j])
			nums[k++] = left[i++];
		else
			nums[k++] = right[j++];
	}

	while (i < lsize)
		nums[k++] = left[i++];

	while (j < rsize)
		nums[k++] = right[j++];
}


void printArray(int* nums, int size) {
	cout << "Array: ";

	for (int i = 0; i < size; i++)
		if (i < size - 1)
			cout << nums[i] << ", ";
		else
			cout << nums[i] << endl;
}
