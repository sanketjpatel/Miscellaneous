/*************************************************************
 * Problem: Return the largest sum of a contiguous sub-array *
 * Author: Sanket Patel										 *
 *************************************************************/

#include <iostream>
using namespace std;

int max(int a, int b){ return (a>b) ? a : b; }

int findMaxSubarray(int * array, int length){
	int max_all=array[0], max_end=array[0];
	for(int i=1; i<length; i++){
		max_end = max(array[i], max_end+array[i]);
		max_all = max(max_all, max_end);
	}
	return max_all;
}

int main() {
	int array[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
	int size = sizeof(array)/sizeof(array[0]);
	cout << findMaxSubarray(array, size);
	return 0;
}
