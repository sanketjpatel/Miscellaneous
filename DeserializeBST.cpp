/************************************************************
 * Problem: Construct a BST from a given preorder traversal *
 * Author: Sanket Patel					    *
 ************************************************************/

#include <iostream>
#include <stack>
using namespace std;

struct node{
	int value;
	node *left, *right;
};

// Create a node with a given value
node* newNode(int value){
	node * temp = new node();
	temp->value = value;
	temp->left = temp->right = NULL;
	return temp;
}

/***********************************
 * 6 2 1 3 4 8 7 9
 *
 * 	    6
 * 	  /   \
 *	 2     8
 *	/ \   / \
 *     1   3 7	 9
 * 	    \
 * 	     4
 ***********************************/

node* constructBST(int * pre, int size){

	node * root = newNode(pre[0]);
	stack<node*> st;

	// cout << "PUSH " << root->value << endl;
	st.push(root);
	node * temp = st.top();

	for(int i=1; i<size; i++){

		node * newnode = newNode(pre[i]);
		temp = st.top();
		while( !st.empty() && newnode->value > st.top()->value){
			temp = st.top();
			// cout << "POP " << temp->value << endl;
			st.pop();			// temp contains the popped element.
		}

		if(newnode->value < temp->value) {
			// cout << temp->value << "-> left = " << newnode->value << endl;
			temp->left = newnode;
		}
		else{
			// cout << temp->value << "-> right = " << newnode->value << endl;
			temp->right = newnode;
		}

		// cout << "PUSH " << newnode->value << endl;
		st.push(newnode);
	}

	return root;
}

void printInorderUtil(node * root){
	if (!root) return;
	printInorderUtil(root->left);
	cout << root->value << ' ';
	printInorderUtil(root->right);
}

void printPreorderUtil(node * root){
	if (!root) return;
	cout << root->value << ' ';
	printPreorderUtil(root->left);
	printPreorderUtil(root->right);
}

void printPostorderUtil(node * root){
	if (!root) return;
	printPostorderUtil(root->left);
	printPostorderUtil(root->right);
	cout << root->value << ' ';
}

void printInorder(node * root){
	printInorderUtil(root);
	cout << endl;
}

void printPreorder(node * root){
	printPreorderUtil(root);
	cout << endl;
}

void printPostorder(node * root){
	printPostorderUtil(root);
	cout << endl;
}

int main() {
	int pre[] = {6, 2, 1, 3, 4, 8, 7, 9};
	node * root = constructBST(pre, sizeof(pre)/sizeof(pre[0]));
	printInorder(root);
	printPreorder(root);
	printPostorder(root);
	return 0;
}
