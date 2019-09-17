#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
	Queue<int> queue;

	for (int i = 0; i < 10; i++) {
		cout << "ADDING: " << i << endl;
		queue.push(i);
	}

	for (int i = 0; i < 5; i++)
		cout << "REMOVING: " << queue.pop() << endl;

	for (int i = 95; i < 98; i++) {
		cout << "ADDING: " << i << endl;
		queue.push(i);
	}

	for (int i = 0; i < 5; i++)
		cout << "REMOVING: " << queue.pop() << endl;

	for (int i = 0; i < 3; i++)
		cout << "REMOVING: " << queue.pop() << endl;

	try {
		queue.pop();
	} catch (const out_of_range& e) {
		cout << "Pop out_of_range successful\n";
	}

	return 0;
}