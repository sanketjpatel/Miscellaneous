/**************************************************************
 * Given a rod of length n inches and an array of prices
 * that contains prices of all pieces of size smaller than n.
 *
 * Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
 *
 * For example, if length of the rod is 8
 * and the values of different pieces are given as following,
 * then the maximum obtainable value is 22
 * (by cutting in two pieces of lengths 2 and 6)
 *
 * length   | 1   2   3   4   5   6   7   8
 * --------------------------------------------
 * price    | 1   5   8   9  10  17  17  20
 *
 * And if the prices are as following,
 * then the maximum obtainable value is 24
 * (by cutting in eight pieces of length 1)
 *
 * length   | 1   2   3   4   5   6   7   8
 * --------------------------------------------
 * price    | 3   5   8   9  10  17  17  20
 *
 * Author: Sanket Patel
 ***************************************************************/

#include <iostream>
using namespace std;

// Approach to solve the problem, use answer to the previous problem.
// price[] is an array of prices. price[i] represents price of rod of length i.
// n is the length of the given rod.
int cutRod(int * price, int n){

	// maxVal will store the solutions of sub-problems.
	// maximum value achievable for a rod of length i.
	int maxVal[n+1];

	// Base case
	maxVal[0] = 0;

	for(int i=1; i<=n; i++){
		maxVal[i] = price[i-1];
		for (int j=1; j<i; j++)
			if(maxVal[j] + maxVal[i-j] > maxVal[i]) maxVal[i] = maxVal[j] + maxVal[i-j];
	}
	return maxVal[n];
}

int main() {
	int price[]={1, 5, 8, 9, 10, 17, 17, 20};
	cout << cutRod(price, sizeof(price)/sizeof(price[0]));
	return 0;
}
