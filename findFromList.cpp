/**********************************************************
 * Problem: Given two lists, find all elements from list2 *
 * such that they exist in list1			  *
 * Order these elements as found in list1		  *
 * Author: Sanket Patel					  *
 **********************************************************/

#include <iostream>
#include <list>
#include <map>

using namespace std;

void printList (list<string> * input) {
	list<string>::iterator itr = input->begin();
	cout << '{';
	if(input->size()){
		cout << *itr;
		for(++itr; itr != input->end(); ++itr) cout << ", " << *itr;
	}
	cout << '}' << endl;
}

list<string> * findFromList (list<string> * templateList, list<string> * receivedList) {

	list<string> * outputList = new list<string>();
	if(templateList->empty() || receivedList->empty()) return outputList;

	map<string, int> countingMap = map<string,int>();
	list<string>::iterator list_itr;

	for (list_itr = templateList->begin(); list_itr != templateList->end(); ++list_itr) countingMap[*list_itr] = 0;
	for (list_itr = receivedList->begin(); list_itr != receivedList->end(); ++list_itr) if(countingMap.find(*list_itr) != countingMap.end()) countingMap[*list_itr]++;

	// map<string, int>::iterator map_itr;
	// for(map_itr = countingMap.begin(); map_itr != countingMap.end(); ++map_itr) cout << map_itr->first << ' ' << map_itr->second << endl;

	for (list_itr = templateList->begin(); list_itr != templateList->end(); ++list_itr) {
		while (countingMap[*list_itr]) {
			outputList->push_back(*list_itr);
			countingMap[*list_itr]--;
		}
	}
	return outputList;
}

int main() {
	list<string> * templateList = new list<string>();
	list<string> * receivedList = new list<string>();
	*templateList = {"Red", "Blue", "Green", "Brown", "White"};
	*receivedList = {"White", "Brown", "Red", "Black", "Yellow", "Brown", "Red", "Blue"};
	// *receivedList = {"Red", "White"};
	list<string> * outputList = findFromList(templateList, receivedList);
	printList(outputList);

	cout << "WIN!";
	return 0;
}
