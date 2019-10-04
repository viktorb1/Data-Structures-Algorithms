#include "avl.h"
#include <iostream>

using namespace std;

int main() {
	AVLTree<int> tree;
	tree.remove(39043);
	tree.insert(5);
	tree.insert(4);
	tree.insert(8);
	tree.insert(3);
	tree.insert(2);
	tree.insert(13);
	tree.insert(16);
	tree.insert(11);
	tree.insert(12);
	tree.print_tree();
	tree.bfs();
	tree.dfs_inorder();
	tree.dfs_preorder();
	tree.dfs_postorder();
	cout << "12 Exists: " << tree.find(12) << endl;
	cout << "39043 Exists: " << tree.find(39043) << endl;
	tree.remove(12);
	tree.insert(15);
	tree.remove(13);
	tree.insert(6);
	tree.insert(7);
	tree.remove(5);
	tree.print_tree();

	// test RR
	// AVLTree<int> tree2;
	// tree2.insert(5);
	// tree2.insert(6);
	// tree2.insert(2);
	// tree2.insert(7);
	// tree2.insert(8);
	// tree2.print_tree();

	// test RL
	// AVLTree<int> tree2;
	// tree2.insert(5);
	// tree2.insert(6);
	// tree2.insert(2);
	// tree2.insert(8);
	// tree2.insert(7);
	// tree2.print_tree();

	// test RR
	// AVLTree<int> tree2;
	// tree2.insert(5);
	// tree2.insert(4);
	// tree2.insert(6);
	// tree2.insert(2);
	// tree2.insert(1);
	// tree2.print_tree();

	// test LR
	// AVLTree<int> tree2;
	// tree2.insert(6);
	// tree2.insert(4);
	// tree2.bfs();
	// tree2.insert(5);
	// tree2.print_tree();
	// tree2.insert(7);
	// tree2.insert(1);
	// tree2.insert(2);
	// tree2.print_tree();


	// test remove()
	// AVLTree<int> tree2;
	// tree2.insert(6);
	// tree2.insert(3);
	// tree2.insert(2);
	// tree2.insert(1);
	// tree2.insert(9);
	// tree2.insert(12);
	// tree2.insert(8);
	// tree2.remove(2);
	// tree2.print_tree();



	return 0;
}