#include "../Queue/Queue.h"
#include <iostream>
using namespace std;

template <typename T>
Node<T>::Node(T data) : data(data), left(NULL), right(NULL), height_left(0), height_right(0) {}


template <typename T>
AVLTree<T>::AVLTree() : root(NULL) {}


template <typename T>
AVLTree<T>::AVLTree(T &data) {
	root = new Node<T>(data);
}


template <typename T>
AVLTree<T>::~AVLTree() {
	destroy_recursive(root);
}


template <typename T>
void AVLTree<T>::destroy_recursive(Node<T> *node) {
	if (node) {
		destroy_recursive(node->left);
		destroy_recursive(node->right);
		delete node;
	}
}


template <typename T>
void AVLTree<T>::insert(const T &data) {
	root = insert_node(root, data);
}


template <typename T>
Node<T>* AVLTree<T>::insert_node(Node<T> *curr, const T &data) {
	if (!curr) {
		return new Node<T>(data);
	} else if (data < curr->data) {
		curr->left = insert_node(curr->left, data);
		curr->height_left = 1 + max(curr->left->height_right, curr->left->height_left);
	} else if (data > curr->data) {
		curr->right = insert_node(curr->right, data);
		curr->height_right = 1 + max(curr->right->height_right, curr->right->height_left);
	}

	curr = check_for_imbalances(curr);
	return curr;
}


template <typename T>
Node<T>* AVLTree<T>::check_for_imbalances(Node<T>* curr) {
	int bf = get_bf(curr);
		
	if (bf == 2) {
		if (get_bf(curr->right) == 1)
			curr = rr_rotation(curr);
		else if (get_bf(curr->right) == -1)
			curr = rl_rotation(curr);
	} else if (bf == -2) {
		if (get_bf(curr->left) == -1)
			curr = ll_rotation(curr);
		else if (get_bf(curr->left) == 1)
			curr = lr_rotation(curr);
	}

	return curr;
}


template <typename T>
int AVLTree<T>::get_bf(Node<T> *curr) {
	return curr->height_right - curr->height_left;
}


template <typename T>
Node<T>* AVLTree<T>::rr_rotation(Node<T>* parent) {
	Node<T>* pivot = parent->right;
	parent->right = pivot->left;

	if (!parent->right)
		parent->height_right = 0;
	else
		parent->height_right = 1 + max(parent->right->height_right, parent->right->height_left);

	pivot->left = parent;
	pivot->height_left = 1 + max(pivot->left->height_right, pivot->left->height_left);
	return pivot;
}


template <typename T>
Node<T>* AVLTree<T>::ll_rotation(Node<T>* parent) {
	Node<T>* pivot = parent->left;
	parent->left = pivot->right;

	if (!parent->left)
		parent->height_left = 0;
	else
		parent->height_left = 1 + max(parent->left->height_right, parent->left->height_left);

	pivot->right = parent;
	pivot->height_right = 1 + max(pivot->right->height_right, pivot->right->height_left);
	return pivot;
}


template <typename T>
Node<T>* AVLTree<T>::lr_rotation(Node<T>* parent) {
	Node<T>* left = parent->left;
	parent->left = rr_rotation(left);
	Node<T>* new_parent = ll_rotation(parent);

	if (!parent->left)
		parent->height_left = 0;
	else
		parent->height_left = 1 + max(parent->left->height_left, parent->left->height_right);
	
	return new_parent;
}


template <typename T>
Node<T>* AVLTree<T>::rl_rotation(Node<T>* parent) {
	Node<T>* right = parent->right;
	parent->right = ll_rotation(right);
	Node<T>* new_parent = rr_rotation(parent);

	if (!parent->right)
		parent->height_right = 0;
	else
		parent->height_right = 1 + max(parent->right->height_left, parent->right->height_right);
	
	return new_parent;
}


template <typename T>
void AVLTree<T>::remove(const T &data) {
	root = remove_node(root, data);
}


template <typename T>
Node<T>* AVLTree<T>::remove_node(Node<T> *curr, const T &data) {
	if (!curr) {
		return NULL;
	} else if (curr->data == data) {
		if (!curr->left) {
			Node<T>* right = curr->right;
			delete curr;
			return right;
		}
		else if (!curr->right) {
			Node<T>* left = curr->left;
			delete curr;
			return left;
		} else {
			Node<T> *min = get_and_disconnect_min(curr->right);
			min->left = curr->left;

			if (min != curr->right)
				min->right = curr->right;

			delete curr;
			return min;
		}
	} else if (data < curr->data) {
		curr->left = remove_node(curr->left, data);

		if (!curr->left)
			curr->height_left = 0;
		else
			curr->height_left = 1 + max(curr->left->height_right, curr->left->height_left);
	} else if (data > curr->data) {
		curr->right = remove_node(curr->right, data);

		if (!curr->right)
			curr->height_right = 0;
		else
			curr->height_right = 1 + max(curr->right->height_right, curr->right->height_left);
	}

	curr = check_for_imbalances(curr);
	return curr;
}


template <typename T>
Node<T>* AVLTree<T>::get_and_disconnect_min(Node<T>* node) {
	Node<T> *parent = NULL;

	while(node && node->left) {
		parent = node;
		node = node->left;
	}

	if (parent) {
		if (!node->right) {
			parent->height_left = 0;
		} else {
			parent->height_left = 1 + max(node->right->height_right, node->right->height_left);
		}

		node->height_right = 0;
		parent->left = node->right;
	}

	return node;
}


template <typename T>
int AVLTree<T>::get_height(Node<T> *curr) {
	if (!curr)
		return 0;

	return max(1 + get_height(curr->left), 1 + get_height(curr->right));
}


template <typename T>
void AVLTree<T>::print_tree() {
    int height = get_height(root); 
    
    for (int i = 0; i < height; i++) { 
        printLevel(root, i); 
        cout << endl;
    }

    cout << endl;
}
  

template <typename T>
void AVLTree<T>::printLevel(Node<T>* curr, int level) 
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
void AVLTree<T>::bfs() {
	Queue<Node<T>*> to_visit;
	Node<T> *curr;

	cout << "BFS: \n";
	to_visit.push(root);

	while(!to_visit.isEmpty()) {
		curr = to_visit.pop();
		cout << curr->data << " ";
		cout << "(" << curr->height_left << ", " << curr->height_right << ") " << endl;

		if (curr->left)
			to_visit.push(curr->left);
		if (curr->right)
			to_visit.push(curr->right);
	}
}


template <typename T>
void AVLTree<T>::dfs_inorder() 
{
	cout << "Inorder: ";
	inorder(root);
	cout << endl;
}


template <typename T>
void AVLTree<T>::inorder(Node<T>* curr) 
{
	if (!curr)
		return;
	
	inorder(curr->left);
	cout << curr->data << " ";
	inorder(curr->right);
}


template <typename T>
void AVLTree<T>::dfs_preorder() 
{
	cout << "Preorder: ";
	preorder(root);
	cout << endl;
}


template <typename T>
void AVLTree<T>::preorder(Node<T>* curr) 
{
	if (!curr)
		return;

	cout << curr->data << " ";
	preorder(curr->left);
	preorder(curr->right);
}


template <typename T>
void AVLTree<T>::dfs_postorder() 
{
	cout << "Postorder: ";
	postorder(root);
	cout << endl;
}


template <typename T>
void AVLTree<T>::postorder(Node<T>* curr) 
{
	if (!curr)
		return;

	preorder(curr->left);
	preorder(curr->right);

	cout << curr->data << " ";
}


template <typename T>
bool AVLTree<T>::find(const T& data) 
{
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