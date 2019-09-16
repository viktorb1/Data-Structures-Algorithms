#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
	Stack<int> stack;

	for (int i = 0; i < 10; i++) {
		cout << "ADDING: " << i << endl;
		stack.push(i);
	}

	for (int i = 0; i < 5; i++)
		cout << "REMOVING: " << stack.pop() << endl;

	for (int i = 95; i < 98; i++) {
		cout << "ADDING: " << i << endl;
		stack.push(i);
	}

	for (int i = 0; i < 5; i++)
		cout << "REMOVING: " << stack.pop() << endl;

	for (int i = 0; i < 3; i++)
		cout << "REMOVING: " << stack.pop() << endl;

	try {
		stack.pop();
	} catch (const out_of_range& e) {
		cout << "Pop out_of_range successful\n";
	}

	return 0;
}