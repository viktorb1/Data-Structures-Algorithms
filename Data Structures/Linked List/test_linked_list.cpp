#include "LinkedList.h"

using namespace std;

int main() {
	List<int> test_list;
	test_list.insert(1,0);
	test_list.print_list();
	cout << "Index at 0 is: " << test_list.get(0) << endl;
	test_list.insert(2,0);
	test_list.print_list();
	test_list.insert(3,2);
	test_list.print_list();
	test_list.insert(4,2);
	test_list.print_list();
	cout << "Index at 2 is: " << test_list.get(2) << endl;
	cout << "Index at 3 is: " << test_list.get(3) << endl;

	try {
		test_list.get(4);
	} catch(const out_of_range& e) {
		cout << "Out of range get() successful.\n";
	}

	try {
		test_list.insert(4,-4);
	} catch(const out_of_range& e) {
		cout << "Out of range insert() successful.\n";
	}

	try {
		test_list.remove(4);
	} catch(const out_of_range& e) {
		cout << "Out of range remove() successful.\n";
	}

	cout << "The size is: " << test_list.get_size() << endl;

	test_list.remove(2);
	test_list.print_list();
	test_list.remove(0);
	test_list.print_list();
	test_list.remove(0);
	test_list.print_list();
	test_list.remove(0);
	test_list.print_list();
	cout << "The size is: " << test_list.get_size() << endl;
	try {
		test_list.remove(0);
	} catch(const out_of_range& e) {
		cout << "Out of range remove() on empty list successful.\n";
	}

	test_list.insert(12,0);
	test_list.print_list();
	cout << "The size is: " << test_list.get_size() << endl;

	return 0;
}