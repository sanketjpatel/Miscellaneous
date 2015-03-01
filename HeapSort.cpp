#include <iostream>
using namespace std;

struct MaxHeap {
	int size;
	int * array;
};

void swap (int * a, int * b) { *a ^= *b, *b ^= *a, *a ^= *b; }

void print (int * array, int size) {
	cout << '{';
	if (size) {
		cout << array[0];
		for (int i = 1; i<size; i++) cout << ", " << array[i];
	}
	cout << '}' << endl;
}

void maxHeapify (int * array, int root_idx, int size) {

	// Need to check for overflow! Check BuildMaxHeap()
	int left_idx = root_idx*2 + 1;
	int right_idx = (root_idx + 1)<<1;

	int largest_idx = root_idx;

	if(left_idx < size && array[left_idx] > array[largest_idx]) largest_idx = left_idx;
	if(right_idx < size && array[right_idx] > array[largest_idx]) largest_idx = right_idx;

	if(largest_idx != root_idx){
		swap( &array[root_idx], &array[largest_idx]);
		maxHeapify(array, largest_idx, size);
	}
}

void BuildMaxHeap (MaxHeap * maxHeap, int * array, int size) {
	maxHeap->size = size;
	maxHeap->array = array;

	// Build from bottom
	// (size-1) is the index of last child
	// Ensures that root_idx is inside the range of int, and its children too are inside the range of int
	int root_idx = (size-2)/2;
	while(root_idx>=0){
		maxHeapify(array, root_idx, size);
		root_idx--;
	}
}

void heapSort (int * array, int size) {
	MaxHeap * maxHeap = new MaxHeap();
	BuildMaxHeap(maxHeap, array, size);
	while(maxHeap->size > 1){
		swap( &array[maxHeap->size - 1], &array[0]);
		maxHeap->size--;
		maxHeapify(array, 0, maxHeap->size);
	}
}

int main() {
	int size = 0, size1 = 15, size2 = 4;
	int array[size] = {};
	int array1[size1] = {1, 5, 3, 2, 4, 9, 6, 10, 8, 7, 15, 12, 14, 11, 13};
	int array2[size2] = {4, 2, 1, 4};
	heapSort(array, size);
	print(array, size);
	heapSort(array1, size1);
	print(array1, size1);
	heapSort(array2, size2);
	print(array2, size2);
	return 0;
}
