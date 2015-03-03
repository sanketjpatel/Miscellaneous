/********************************************************
 * Problem: Count the minimum number of splits		*
 * required to make palindromes from  a given string	*
 * Author: Sanket Patel					*
 ********************************************************/

#include <iostream>
#include <cstring>
using namespace std;

// Utility function and variables
int min (int a, int b) { return (a < b)? a : b; }
const int INT_MAX = ~(1<<(8*sizeof(INT_MAX)-1));

bool isPalindrome(char * str, int left, int right){
	for (int i=0; i < (right-left + 1)/2; i++) if(str[left + i] != str[right - i]) return false;
	return (left <= right) ? true : false;
}

bool isPalindrome(char * str){ return isPalindrome(str, 0, strlen(str)-1); }

int countMinSplitsRecursive(char * str, int l, int r){
	if(l == r) return 0;
	if(isPalindrome(str, l, r)) return 0;

	int counter = INT_MAX;
	for(int i=l; i<r; i++){
		counter = min(counter, countMinSplitsRecursive(str, l, i) + 1 + countMinSplitsRecursive(str, i+1, r));
	}
	return counter;
}

int countMinSplitsRecursive(char * str){ return countMinSplitsRecursive(str, 0, strlen(str)-1);}

int countMinSplitsDynamic(char * str){
	int length = strlen(str);

	// counts[i][j] represents splits required from str.substr(i, j+1).
	// palindromes[i][j] represents if str.substr(i, j+1) is palindrome or not.
	int counts[length][length];
	bool palindromes[length][length];

	for (int i=0; i<length; i++) palindromes[i][i] = true, counts[i][i] = 0;

	// L represents length of substring
	for(int L = 2; L<=length; L++){

		// i represents start index of substring
		for(int i=0; i<length-L+1; i++){
			// j represents end index of substring
			int j = i + L - 1;

			// Set value for palindrome[i][j]
			if (L == 2) palindromes[i][j] = (str[i] == str[j]);
            else palindromes[i][j] = (str[i] == str[j]) && palindromes[i+1][j-1];

            if(palindromes[i][j]) counts[i][j]=0;
            else{
            	counts[i][j] = INT_MAX;
            	// check for all possible splits
            	for(int k=i; k<j; k++) counts[i][j] = min(counts[i][j], counts[i][k] + counts[k+1][j]+1);
            }
		}
	}

	return counts[0][length-1];
}

int countMinSplits(string str){
	char charArray[str.length()];
	strcpy(charArray, str.c_str());
	return countMinSplitsDynamic(charArray);
}

int main() {
	char * str = "abcabacbaxyxxy";
	char * str2 = "a";
	char * str3 = "ababbbabbababa";
	cout << countMinSplits(str) << endl;
	cout << countMinSplits(str2) << endl;
	cout << countMinSplits(str3) << endl;
	return 0;
}
