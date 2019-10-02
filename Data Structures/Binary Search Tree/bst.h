#ifndef _BST_H_
#define _BST_H_

template <typename T>
class BST;


template <typename T>
class Node {
	T data;
	Node<T> *left, *right;
	friend BST<T>;
public:
	Node(T data);
};


template <typename T>
class BST {
	Node<T>* root;
	int get_height(Node<T>* curr);
	void printLevel(Node<T>* root, int level);
	void destroy_recursive(Node<T> *node);
	Node<T>* get_and_disconnect_min(Node<T>* node);
	void remove(const T &value, Node<T>* &node);
	void inorder(Node<T>* curr);
	void preorder(Node<T>* curr);
	void postorder(Node<T>* curr);
public:
	BST();
	BST(T &root);
	~BST();
	void insert(const T &data);
	void remove(const T &data);
	void print_tree();
	void bfs();
	void dfs_inorder();
	void dfs_preorder();
	void dfs_postorder();
	bool find(const T &data);


};


#include "bst.cpp"
#endif