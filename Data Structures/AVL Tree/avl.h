#ifndef _AVL_H_
#define _AVL_H_

template <typename T>
class AVLTree;


template <typename T>
class Node {
	T data;
	Node<T> *left, *right;
	int height_left, height_right;
	friend AVLTree<T>;
public:
	Node(T data);
};


template <typename T>
class AVLTree {
	Node<T>* root;
	int get_height(Node<T>* curr);
	void printLevel(Node<T>* root, int level);
	void destroy_recursive(Node<T> *node);
	Node<T>* get_and_disconnect_min(Node<T>* node);
	void remove(const T &value, Node<T>* &node);
	void inorder(Node<T>* curr);
	void preorder(Node<T>* curr);
	void postorder(Node<T>* curr);
	Node<T>* insert_node(Node<T> *curr, const T &data);
	Node<T>* check_for_imbalances(Node<T>* curr);
	Node<T>* remove_node(Node<T> *curr, const T &data);
	Node<T>* rr_rotation(Node<T>* parent);
	Node<T>* ll_rotation(Node<T>* parent);
	Node<T>* lr_rotation(Node<T>* parent);
	Node<T>* rl_rotation(Node<T>* parent);
	int get_bf(Node<T> *curr);
public:
	AVLTree();
	AVLTree(T &root);
	~AVLTree();
	void insert(const T &data);
	void remove(const T &data);
	void print_tree();
	void bfs();
	void dfs_inorder();
	void dfs_preorder();
	void dfs_postorder();
	bool find(const T &data);
};


#include "avl.cpp"
#endif