#ifndef _DOUBLYLINKEDLIST_H_
#define _DOUBLYLINKEDLIST_H_

template <typename T>
class ListNode;

template <typename T>
class List {
	ListNode<T>* head;
	ListNode<T>* tail;
	int size;
	void remove_at_head();
	void remove_at_tail();
	void insert_at_head(ListNode<T>* data);
	void insert_at_tail(ListNode<T>* data);
public:
	List();
	void remove(int i);
	void insert(const T& data, int i);
	T get(int i);
	int get_size();
	void print_list();
	void print_list_reverse();

};


template <typename T>
class ListNode {
	T data;
	ListNode* next;
	ListNode* prev;
	ListNode();
	friend class List<T>;
public:
	ListNode(const T& data);
};


#include "DoublyLinkedList.cpp"

#endif