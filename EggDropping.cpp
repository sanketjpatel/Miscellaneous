/******************************************************************************
 * Find the solution to a general problem with n eggs and k floors.
 * The solution is to try dropping an egg from every floor (from 1 to k)
 * and calculate the minimum number of droppings needed in worst case.
 *
 * The floor which gives the minimum value in worst case is going to be part of the solution.
 *
 * Author: Sanket Patel
 ******************************************************************************/

#include <iostream>
#include <string.h>
using namespace std;

int INT_MAX = ~(1<<(8*sizeof(INT_MAX)-1));

/**
 * Approach: Say I drop an egg on floor x. Two possibilities -
 * 1. Egg breaks => Calculate minEggDroppings(numEggs - 1, x-1)
 * 2. Egg doesn't break => Calculate minEggDroppings(numEggs, numFloors - x)
 *
 * Take max of these two, and store it in drops[numEggs][x]
 * drops[i][j] represents the solution for i eggs from j floor
 */

int minEggDroppings(int numEggs, int numFloors){

	int drops[numEggs+1][numFloors+1];
	memset(drops, 0, sizeof(drops));
	int dummy;

	/* Base Cases */
	for(int i=1; i<=numEggs; i++){
		drops[i][1] = 1;	// Only one drop needed for 1 floor
		drops[i][0] = 0;	// Zero drops needed for no floors
	}
	for(int j=2; j<=numFloors; j++) drops[1][j] = j;

	// Build the table in a bottom up fashion.
	for(int i=2; i<=numEggs; i++){
		for(int j=2; j<=numFloors; j++){
			drops[i][j] = INT_MAX;
			for(int x=1; x<=j; x++){
				dummy = 1 + max(drops[i-1][x-1], drops[i][j-x]);
				if (drops[i][j] > dummy) drops[i][j] = dummy;
			}
		}
	}

	for(int i=0; i<=numEggs; i++){
		for(int j=0; j<=numFloors; j++){
			cout << drops[i][j] << ' ';
		}
		cout << endl;
	}

	return drops[numEggs][numFloors];
}

int main() {
	int numEggs = 7;
	int numFloors = 100;
	cout << "Minimum worst case egg drops required for " << numEggs << " eggs and " << numFloors << " floors = " << minEggDroppings(numEggs, numFloors);
	return 0;
}
