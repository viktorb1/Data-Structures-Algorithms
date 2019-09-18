#include <iostream>
using namespace std;

template <typename T>
List<T>::List() : head(NULL), size(0) {}


template <typename T>
ListNode<T>::ListNode(const T& data) : data(data), next(NULL) {}


template <typename T>
void List<T>::remove(int i) {
	ListNode<T>* prev = NULL, *curr = head;

	if (i >= size || i < 0)
		throw out_of_range("Index for remove is too large");

	if (i == 0) { // delete at head
		head = head->next;
		delete curr;
		size--;
		return;
	}

	while (curr != NULL && i > 0) { // delete at middle or end
		prev = curr;
		curr = curr->next;
		i--;
	}

	prev->next = curr->next;
	delete curr;
	size--;
}


template <typename T>
void List<T>::insert(const T& data, int i) {
	ListNode<T>* curr = head, *prev = NULL;

	if (i > size || i < 0)
		throw out_of_range("Index for insert is too large");

	ListNode<T>* to_add = new ListNode<T>(data);

	if (i == 0) {
		to_add->next = head;
		head = to_add;
		size++;
		return;
	}

	while (curr != NULL && i > 0) {
		prev = curr;
		curr = curr->next;
		i--;
	}

	prev->next = to_add;
	to_add->next = curr;
	size++;
}


template <typename T>
T List<T>::get(int i) {
	ListNode<T>* curr = head, *prev = NULL;

	if (i >= size || i < 0)
		throw out_of_range("Index does not exist");

	while (curr != NULL && i >= 0) {
		prev = curr;
		curr = curr->next;
		i--;
	}

	return prev->data;
}

template <typename T>
int List<T>::get_size() {
	return size;
}

template <typename T>
void List<T>::print_list() {
	ListNode<T>* curr = head;

	while (curr != NULL) {
		cout << curr->data << "->";
		curr = curr->next;
	}

	cout << "NULL\n";
}