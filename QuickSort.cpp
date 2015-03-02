#include <iostream>
using namespace std;

void swap(int* a, int* b){
	int temp = *a;
    	*a = *b;
	*b = temp;
}

void print (int * array, int size) {
	cout << '{';
	if(size){
		cout << array[0];
		for (int i=1; i<size; i++) cout << ", " << array[i];
	}
	cout << '}' << endl;
}

void quickSort(int arr[], int left, int right){

	if (left < right){

    		int pivot = arr[right];
	    	int left_runner = left;	// left_runner represents the first element of the right subarray; elements > pivot.

    		for (int right_runner=left_runner; right_runner < right; right_runner++){
    			if (arr[right_runner] <= pivot){
		            swap(&arr[left_runner], &arr[right_runner]);
		            left_runner++;
		        }
		}
		swap(&arr[left_runner], &arr[right]);

		quickSort(arr, left, left_runner-1);
		quickSort(arr, left_runner+1, right);
	}
}

void quickSort(int * array, int size) { quickSort(array, 0, size-1); }

int main() {

	const int size = 15;
	int array[size] = {1, 5, 2, 4, 3, 15, 13, 8, 12, 9, 6, 10, 11, 7, 14};
	print(array, size);
	quickSort(array, size);
	print(array, size);

	return 0;
}
