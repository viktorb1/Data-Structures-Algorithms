using namespace std;

#include <iostream>

void printArray(int *nums, int size);
void quick_sort(int* nums, int p, int r);
int partition(int* nums, int p, int r);
int medianOfThree(int* nums, int p, int r);


int main() {
	const int size = 10;
	int nums[size] = {-9, 2, 2, 9, 31, 12, 3, 5, -4, -3};
	printArray(nums, size);
	quick_sort(nums, 0, size-1);
	printArray(nums, size);
	return 0;
}


void quick_sort(int* nums, int p, int r) {
	if (p < r) {
		int q = partition(nums, p, r);
		quick_sort(nums, p, q-1);
		quick_sort(nums, q+1, r);
	}
}

int partition(int* nums, int p, int r) {
	int m = medianOfThree(nums, p, r);

	swap(nums[m], nums[r]);

	int divider = p - 1; // index of last smaller number
	for (int i = p; i < r; i++) {
		if (nums[i] < nums[r]) {
			divider++;
			swap(nums[divider], nums[i]);
		}
	}

	swap(nums[divider+1], nums[r]);
	return divider+1;
}


int medianOfThree(int* nums, int p, int r) {
	int m = (p + r)/2;

	if (nums[p] < nums[m]) {
		if (nums[p] > nums[r])
			return p;
		else if (nums[m] < nums[r])
			return m;
		else
			return r;
	} else {
		if (nums[p] < nums[r])
			return p;
		else if (nums[m] > nums[r])
			return m;
		else
			return r;
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
