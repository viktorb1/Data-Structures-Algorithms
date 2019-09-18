#include <iostream>
using namespace std;

template <typename T>
List<T>::List() : head(NULL), tail(NULL), size(0) {}


template <typename T>
ListNode<T>::ListNode(const T& data) : data(data), prev(NULL), next(NULL) {}


template <typename T>
void List<T>::remove(int i) {
	ListNode<T>* curr = head;

	if (i >= size || i < 0)
		throw out_of_range("Index for remove is too large");

	if (i == 0) { // delete at head
		remove_at_head();
	} else if (i == size - 1) { // delete at tail
		remove_at_tail();
	} else { // delete at middle
		while (curr != NULL && i > 0) { 
			curr = curr->next;
			i--;
		}

		curr->prev->next = curr->next;
		delete curr;
		size--;
	}
}


template <typename T>
void List<T>::remove_at_head() {
	ListNode<T>* to_delete = head;
	head = head->next;
	delete to_delete;
	size--;
}


template <typename T>
void List<T>::remove_at_tail() {
	ListNode<T>* to_delete = tail;
	to_delete->prev->next = NULL;
	delete to_delete;
	size--;
}



template <typename T>
void List<T>::insert(const T& data, int i) {
	ListNode<T>* curr = head;

	if (i > size || i < 0)
		throw out_of_range("Index for insert is too large");

	ListNode<T>* to_add = new ListNode<T>(data);

	if (i == 0) {
		insert_at_head(to_add);
	} else if (i == size) {
		insert_at_tail(to_add);
	} else {
		while (curr->next != NULL && i > 0) {
			curr = curr->next;
			i--;
		}

		(curr->prev)->next = to_add;
		to_add->next = curr;
		to_add->prev = curr->prev;
		curr->prev = to_add;
		size++;
	}
}


template <typename T>
void List<T>::insert_at_head(ListNode<T>* data) {
	data->next = head;
	data->prev = NULL;

	if (head)
		head->prev = data;

	head = data;

	if (!tail)
		tail = head;

	size++;
}


template <typename T>
void List<T>::insert_at_tail(ListNode<T>* data) {
	data->next = NULL;
	data->prev = tail;

	if (tail)
		tail->next = data;

	tail = data;
	size++;
}


template <typename T>
T List<T>::get(int i) {
	ListNode<T>* curr = head;

	if (i >= size || i < 0)
		throw out_of_range("Index does not exist");

	while (curr->next != NULL && i > 0) {
		curr = curr->next;
		i--;
	}

	return curr->data;
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


template <typename T>
void List<T>::print_list_reverse() {
	ListNode<T>* curr = tail;

	while (curr != NULL) {
		cout << curr->data << "->";
		curr = curr->prev;
	}

	cout << "NULL\n";
}