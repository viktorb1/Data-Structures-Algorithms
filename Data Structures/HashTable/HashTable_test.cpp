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

	string multi_add;


	for (int i = 0; i < 30; i++) {
		multi_add += i+97;
		test.insert(multi_add, i);
	}

	cout << "The key for abcde is : " << test.get("abcde") << endl;

	test.printHashTable();

	multi_add.clear();

	for (int i = 0; i < 30; i++) {
		multi_add += i+97;

		if (multi_add == "abcdefgh")
			cout << "DELETING abcdefgh\n\n\n";

		test.remove(multi_add);
	}

	test.printHashTable();

	cout << "THE SIZE IS: " << test.getSize() << endl;

	return 0;
}