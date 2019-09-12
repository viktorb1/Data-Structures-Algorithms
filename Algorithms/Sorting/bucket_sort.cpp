using namespace std;

#include <iostream>
#include <cmath>


void printArray(int *nums, int size);
void bucket_sort(int* nums, int size);
int getMax(int* nums, int size);


class ListNode;
class List {
public:
	ListNode* head;
	List();
	void insertToList(int to_add);
};

class ListNode {
public:
	int data;
	ListNode* next;
	ListNode(int to_add);
};

List::List() : head(NULL) {}
ListNode::ListNode(int to_add) : data(to_add), next(NULL) {}


int main() {
	const int size = 10;
	int nums[size] = {9, 2, 2, 8, 31, 12, 3, 5, 4, 3};
	printArray(nums, size);
	bucket_sort(nums, size);
	printArray(nums, size);
}


void bucket_sort(int* nums, int size) {
	List* sorted[size];
	int divider = ceil(float(getMax(nums, size) + 1) / size);

	for(int i = 0; i < size; i++)
		sorted[i] = new List();

	for(int i = 0; i < size; i++)
		(sorted[(nums[i]) / divider])->insertToList(nums[i]);

	int j = 0;
	for (int i = 0; i < size; i++) {
		ListNode* curr = sorted[i]->head;
		while (curr) {
			nums[j++] = curr->data;
			curr = curr->next;
		}
	}
}

int getMax(int* nums, int size) {
	int max = nums[0];
	for (int i = 1; i < size; i++)
		if (nums[i] > max)
			max = nums[i];

	return max;
}

void List::insertToList(int to_add) {
	ListNode* newNode = new ListNode(to_add);
	ListNode* curr = head;
	ListNode* prev = NULL;

	if (!curr)
		head = newNode;
	else {
		while (curr && curr->data < to_add) {
			prev = curr;
			curr = curr->next;
		}

		if (curr == head) {
			newNode->next = curr;
			head = newNode;
		} else {
			prev->next = newNode;
			newNode->next = curr;
		}

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
