/************************ 
 * Reverse an int	*
 * Author: Sanket Patel *
 ************************/
 
#include <iostream>
#include <iomanip>

using namespace std;

int reverse(int num) throw (int){
	int numCopy = num;			// Throw original number in case of error
	
	int ans=0;
	int x = ~(1<<(8*sizeof(num)-1));	// Range of int on the positive side
	//int flag = (x < 0) ? -1 : 1;		// Mod(%) takes care of negative numbers too, flag not needed.
	
	while(num/10 != 0){			// We don't need to worry about overflow until last digit
		ans = (ans*10) + (num%10);
		num /= 10;
	}
	
	// ans must eventually lie in the range of int
	if ( (ans > ((x/10)-num)) || (ans < (((~x)/10)-num)) ){		
		cout << "Cannot reverse this number: ";
		throw numCopy;
	} 
	
	return ans*10 + num;
}

int main() {
	// your code goes here
	
	int big1 = (1<<(8*sizeof(big1)-1))+7;
	int big2 = (~(1<<(8*sizeof(big2)-1)))-6;
	int big3 = ~(1<<(8*sizeof(big3)-1)) - 5;		// To check big numbers
	
	int arr [] = {0, 1, -1, -13, 42, 123, -2354, big1, big2, big3};
	
	try{
		for(int i=0; i<sizeof(arr)/sizeof(*arr); i++) cout << setw(20) << arr[i] << setw(20) << reverse(arr[i]) << endl;
	}
	catch (int e) {
		cout << e << endl;
	}
	return 0;
}
