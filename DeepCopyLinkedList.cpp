/*******************************
 * Problem: Deep copy a linked list with nodes containing arbit pointers
 * Author: Sanket Patel
 *******************************/

#include <iostream>
#include <unordered_map>
using namespace std;

struct node{
	int data;
	node * next;
	node * arbit;
};

// Node Constructor
node * newNode(int data){
	node * head = new node();
	head->data = data;
	head->next = NULL;
	head->arbit = NULL;
	return head;
}

// lookupTable maps nodes from original linked list to the corresponding nodes in copied linked list
unordered_map <node*, node*> lookupTable;

// Performs a deep copy of the linkedlist
node * deepCopy(node * head){

	if(!head) return NULL;

	node * head_new = new node();
	lookupTable[head] = head_new;

	head_new->data = head->data;
	head_new->next = deepCopy(head->next);			// Deep copy everything next to head pointer. Lookup Table is ready with all nodes.
	head_new->arbit = lookupTable[head->arbit];		// Set arbit for the copied head.

	return head_new;
}

/**
 * Utility Functions to test the code
 * */

// Utility function to print values stored in linkedlist
// If arbit node exists, the value stored in arbit is shown next to the current node
// Next node is shown on the next line.
void printList(node * head){
	while(head){
		cout << head->data;
		if(head->arbit) cout << "->" << head->arbit->data;
		cout << endl;
		head = head->next;
	}
}

// Utility function to print addresses of nodes in linkedlist
// If arbit node exists, the address of the arbit node is shown next to the current node
// Next node is shown on the next line.
void printAddresses(node * head){
	while(head){
		cout << head;
		if(head->arbit) cout << "->" << head->arbit;
		cout << endl;
		head = head->next;
	}
}

int main() {
	lookupTable[NULL] = NULL;

	/**
	 * Create a test linked list
	 *
	 * 	     _______________
	 * 	    |		    |
	 *  	   _|_     ___     _v_     ___
	 * head-->|_1_|-->|_2_|-->|_3_|-->|_4_|-->NULL
	 *		    ^		    |
	 *  		    |_______________|
	 *
	 * Kudos! That was a bit of neat work, haha :)
	 * */

	node * head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->arbit = head->next->next;
	head->next->next->next->arbit = head->next;

	// Perform a deep copy of the given linkedlist.
	node * head_new = deepCopy(head);

	cout << "Original List" << endl;
	printList(head);
	cout << endl << "Copied List" << endl;
	printList(head_new);
	cout << endl << "Original List" << endl;
	printAddresses(head);
	cout << endl << "Copied List" << endl;
	printAddresses(head_new);

	return 0;
}
