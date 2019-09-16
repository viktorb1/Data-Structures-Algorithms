#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
	Stack<int> stack;

	for (int i = 0; i < 10; i++) {
		cout << "ADDING: " << i << endl;
		stack.push(i);
	}

	for (int i = 0; i < 10; i++)
		cout << "REMOVING: " << stack.pop() << endl;

	return 0;
}