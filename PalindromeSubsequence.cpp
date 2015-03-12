/*******************************************************************
 * Problem: Find the length of the longest palindromic subsequence *
 * Author: Sanket Patel											   *
 *******************************************************************/

#include <iostream>
#include <string.h>
// #include <cmath>
using namespace std;

int palinSubseqLength(char * str){

	// n represents the length of the string
	int n = strlen(str);

	// counter is a table that stores the values of subproblems
	// counter[i][j] represents the length of the longest palindromic
	// subsequence of the substring str[i..j]
	// Final answer will be in counter[0][n-1]
	int counter[n][n];
	memset(counter, 0, sizeof(counter));

	// Initialize table values for substrings of lengths 1 and 2.
	counter[0][0] = 1;
	for (int i=1; i<n; i++){
		counter[i][i] = 1;
		counter[i-1][i] = (str[i-1] == str[i]) ? 2 : 1;
	}

	// Build in bottom-up fashion, substring lengths increasing from 3 to n.
	for (int L=3; L<=n; L++){
		for (int i=0; i<=n-L; i++){
			int j = i+L-1;
			if(str[i]==str[j]) counter[i][j] = 2 + counter[i+1][j-1];
			else counter[i][j] = (counter[i+1][j] > counter[i][j-1]) ? counter[i+1][j] : counter[i][j-1];
		}
	}

	/* DEBUGGING */
	// Print table values
	cout << "  ";
	for (int i=0; i<n; i++) cout << str[i] << ' ';
	cout << endl;
	for (int i=0; i<n; i++){
		cout << str[i] << ' ';
		for (int j=0; j<n; j++){
			cout << counter[i][j] << ' ';
		}
		cout << endl;
	}

	return counter[0][n-1];
}

int main() {
	char * str = "SANKET PATEL";
	// cout << str << endl;
	cout << endl << "The length of longest palindromic subsequence is " << palinSubseqLength(str) << endl;
	return 0;
}
