#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
	HashTable<string, int> test;

	test.insert("John", 45);
	test.insert("Mary", 24);
	test.insert("John", 48);

	cout << "The key for John is : " << test.get("John") << endl;
	test.remove("John");
	test.remove("John");

	string multi_add = "a";


	for (int i = 0; i < 30; i++) {
		multi_add += i+98;
		test.insert(multi_add, i);
	}

	test.printHashTable();

	return 0;
}