/***************************************************************** 
 * Print all 4 digit numbers which have the following property:  *
 * The sum of first 2 digits and last 2 digits = middle 2 digits *
 * Author: Sanket Patel                                          *
 *****************************************************************/

#include <iostream>
#include <list>
using namespace std;

list<int> foo(){
	list <int> fooList;
	for(int i=10; i<100; i++){				// i represents first 2 digits
		for (int j=1; j<100; j++){			// j represents last 2 digits
			if(((i%10)*10 + j/10) == (i+j)){	// check the property
				fooList.push_back(i*100 + j);
				break;				// because only one j exists for a given i
			}
		}
	}
	return fooList;
}

int main() {
	// your code goes here
	list <int> fooLish = foo();
	
	list <int> :: iterator itr;
	for (itr= fooLish.begin(); itr!= fooLish.end(); ++itr) cout << *itr << endl;
	
	return 0;
}
