#include <iostream>
#include <cmath>

using namespace std;

const int MAX_K = 500;

int primes[MAX_K];

// Initialize the array for primes
void initPrimes(){
	primes[0] = 2;
	primes[1] = 3;
	for(int i=2; i<MAX_K; i++) primes[i] = 0;
}

// Function Declaration
bool isPrime(int);

// Returns the k-th prime number. Set of prime numbers = {2, 3, 5, 7, 11, 13, ...}
int findKthPrime(int k){

	// Return the value if we have already calculated it before
	if(primes[k] != 0) return primes[k];

	// 'previous' will be an odd number because we initialized 'primes' as {2, 3, ...}.
	// Base case gives 3.
	int previous = findKthPrime(k-1);
	int ans = previous+2;

	while(!isPrime(ans)) ans += 2;	// No need to check for even numbers

	primes[k] = ans;
	return ans;
}

// Check if the given int is a prime number or not.
// Returns true if it is a prime, otherwise returns false
bool isPrime(int n){

	int limit = sqrt(n);	// No need to check for primes beyond this limit

	for(int i=0; 1; i++){

		// Ideally, primes[i] should be non-zero.
		// Putting this just in case, if it is called by some function other than findKthPrime.
		if(primes[i] == 0) primes[i] == findKthPrime(i);
		if(primes[i] > limit) break;

		if(n%primes[i] == 0) return false;
	}
	return true;
}


// Print the array of primes.
void printPrimes(){
	cout << '{' << primes[0];
	for(int i=1; primes[i]!=0; i++)	cout << ',' << ' ' << primes[i];
	cout << '}' << endl;
}

int main() {

	initPrimes();

	int k;
	cout << "\nFind k-th prime number for k = ";
	cin >> k;
	cout << findKthPrime(k-1) << endl << endl;
	cout << "List of primes: ";
	printPrimes();

	int checkNum;
	cout << "\nEnter a number to check primality: ";
	cin >> checkNum;
	cout << "isPrime(" << checkNum << ") = " << isPrime(checkNum) << endl << endl;

	return 0;
}
