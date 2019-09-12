#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

class MaxHeap {
	int* heap;
	int heap_size;
	int array_size;

public:
	MaxHeap() = delete;
	MaxHeap(int size);
	MaxHeap(int *data, int array_length);
	~MaxHeap();
	int getMax();
	int extractMax();
	void increaseKey(int i, int increase_by);
	void decreaseKey(int i, int decrease_by);
	void insert(int key);
	int remove(int i);
	void printHeap();

private:
	int parent(int i);
	int right(int i);
	int left(int i);
	void percolate_up(int i);
	void percolate_down(int i);
	void resize();
};

#endif