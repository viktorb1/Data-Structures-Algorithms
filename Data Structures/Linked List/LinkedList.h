#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

template <typename T>
class ListNode;

template <typename T>
class List {
	ListNode<T>* head;
	int size;
public:
	List();
	void remove(int i);
	void insert(const T& data, int i);
	T get(int i);
	int get_size();
	void print_list();

};


template <typename T>
class ListNode {
	T data;
	ListNode* next;
	ListNode();
	friend class List<T>;
public:
	ListNode(const T& data);
};


#include "LinkedList.cpp"

#endif