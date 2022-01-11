#include <iostream>
using namespace std;

class Node {

// Properties are defined public here because we are accessing it directly inside main to set the data and the left and right node.
// U will have to set getter and setter functions to make it private.

public:
	int data;
	Node *left;
	Node *right;

	Node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

int main() {
	Node *root = new Node(5);

	root->left = new Node(6);
	root->left->left = new Node(8);
	root->left->right = new Node(9);
	root->left->right->left = new Node(10);

	root->right = new Node(7);

	cout << root->data << " ";
	cout << root->right->data << " ";
	return 0;
}