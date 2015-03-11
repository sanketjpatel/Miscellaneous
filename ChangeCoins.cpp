/******************************************************************************
 * Problem: Return the number of ways you can make change for a given amount.
 *
 * Approach - Consider initially there are no coins.
 * Take first coin, and store the ways you can make change for all amounts in a table.
 * Now take second coin, and add the ways you can make change for all amounts to the previously stored values in the table.
 * Repeat the process.
 *
 * Author: Sanket Patel
 ******************************************************************************/

#include <iostream>
using namespace std;

int coinChange(int amount, int * coin, int numCoins){
	int changeTable[amount+1];

	// Initialize the values for the table
	changeTable[0] = 1;	// If amount is zero, there is one way to provide it. The change is no coins at all.
	for(int j=1; j<=amount; j++) changeTable[j] = 0;

	for(int i=0; i<numCoins; i++){
		for(int j=coin[i]; j<=amount; j++){
			// Previously stored value = Ways you could make the change without the new coin
			// Updated stored value = Ways you can make the change with the new coin
			// Update step = previous value + ways to make change for the amount (j - value of new coin)
			changeTable[j] += changeTable[j-coin[i]];
		}
	}
	return changeTable[amount];
};


int main() {
	int coin[] = {1, 2, 3};
	int amount = 4;
	cout << coinChange(amount, coin, sizeof(coin)/sizeof(coin[0])) << endl;
	return 0;
}
