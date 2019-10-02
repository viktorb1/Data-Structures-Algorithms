#include "../Queue/Queue.h"
#include <iostream>
using namespace std;

template <typename T>
Node<T>::Node(T data) : data(data), left(NULL), right(NULL) {}


template <typename T>
BST<T>::BST() : root(NULL) {}


template <typename T>
BST<T>::BST(T &data) {
	root = new Node<T>(data);
}


template <typename T>
BST<T>::~BST() {
	destroy_recursive(root);
}

template <typename T>
void BST<T>::destroy_recursive(Node<T> *node) {
	if (node) {
		destroy_recursive(node->left);
		destroy_recursive(node->right);
		delete node;
	}
}


template <typename T>
void BST<T>::insert(const T &data) {
	Node<T>* new_node = new Node<T>(data);

	Node<T>* to_insert = root;
	Node<T>* parent = NULL;

	while (to_insert) {
		parent = to_insert;

		if (to_insert->data > data)
			to_insert = to_insert->left;
		else
			to_insert = to_insert->right;
	}

	if (!parent) {
		root = new_node;
	} else if (parent->data > data) {
		parent->left = new_node;
	} else {
		parent->right = new_node;
	}
}

template <typename T>
void BST<T>::remove(const T &data) {
	Node<T> *to_remove = root, *parent = NULL;

	while (to_remove) {
		if (to_remove->data == data) {
			break;
		} else if (to_remove->data > data) {
			parent = to_remove;
			to_remove = to_remove->left;
		} else {
			parent = to_remove;
			to_remove = to_remove->right;
		}
	}

	if (to_remove && !to_remove->left) {
		if (to_remove == root)
			root = to_remove->right;
		else if (parent->right == to_remove)
			parent->right = to_remove->right;
		else
			parent->left = to_remove->right;

		delete to_remove;
	} else if (to_remove && !to_remove->right) {
		if (to_remove == root)
			root = to_remove->left;
		else if (parent->right == to_remove)
			parent->right = to_remove->left;
		else
			parent->left = to_remove->left;

		delete to_remove;
	} else if (to_remove && to_remove->left && to_remove->right) {
		Node<T> *new_node = get_and_disconnect_min(to_remove->right);
		
		if (to_remove == root)
			root = new_node;
		else if (parent->right == to_remove)
			parent->right = new_node;
		else
			parent->left = new_node;

		new_node->left = to_remove->left;

		if (new_node != to_remove->right)
			new_node->right = to_remove->right;

		delete to_remove;
	}
}

template <typename T>
Node<T>* BST<T>::get_and_disconnect_min(Node<T>* node) {
	
	Node<T> *parent = NULL;

	while(node && node->left) {
		parent = node;
		node = node->left;
	}

	if (parent)
		parent->left = node->right;

	return node;
}


template <typename T>
int BST<T>::get_height(Node<T> *curr) {
	if (!curr)
		return 0;

	return max(1 + get_height(curr->left), 1 + get_height(curr->right));
}


template <typename T>
void BST<T>::print_tree() {
    int height = get_height(root); 
    
    for (int i = 0; i < height; i++) { 
        printLevel(root, i); 
        cout << endl;
    }
}
  
template <typename T>
void BST<T>::printLevel(Node<T>* curr, int level) 
{ 
    if (!curr)
        cout << " * "; 
    else if (level == 0) 
        cout <<  " " << curr->data << " "; 
    else if (level > 0) 
    {
        printLevel(curr->left, level - 1); 
        printLevel(curr->right, level - 1); 
    }
} 


template <typename T>
void BST<T>::bfs() {
	Queue<Node<T>*> to_visit;
	Node<T> *curr;

	cout << "BFS: ";
	to_visit.push(root);

	while(!to_visit.isEmpty()) {
		curr = to_visit.pop();
		cout << curr->data << " ";
		
		if (curr->left)
			to_visit.push(curr->left);
		if (curr->right)
			to_visit.push(curr->right);
	}

	cout << endl;
}


template <typename T>
void BST<T>::dfs_inorder() {
	cout << "Inorder: ";
	inorder(root);
	cout << endl;
}

template <typename T>
void BST<T>::inorder(Node<T>* curr) {

	if (!curr)
		return;
	
	inorder(curr->left);

	cout << curr->data << " ";

	inorder(curr->right);

}


template <typename T>
void BST<T>::dfs_preorder() {
	cout << "Preorder: ";
	preorder(root);
	cout << endl;
}


template <typename T>
void BST<T>::preorder(Node<T>* curr) {

	if (!curr)
		return;

	cout << curr->data << " ";

	preorder(curr->left);
	preorder(curr->right);

}


template <typename T>
void BST<T>::dfs_postorder() {
	cout << "Postorder: ";
	postorder(root);
	cout << endl;
}


template <typename T>
void BST<T>::postorder(Node<T>* curr) {

	if (!curr)
		return;

	preorder(curr->left);
	preorder(curr->right);

	cout << curr->data << " ";
}


template <typename T>
bool BST<T>::find(const T& data) {
	Node<T> *curr = root;
	while(curr) {
		if (curr->data == data)
			return true;
		if (curr->data > data) {
			curr = curr->left;
		} else {
			curr = curr->right;
		}
	}

	return false;
}