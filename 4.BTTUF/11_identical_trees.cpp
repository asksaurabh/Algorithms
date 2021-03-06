#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
	int data;
	Node *left, *right;

	Node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

void isIdentical(Node* root1, Node* root2) {

	if (root1 == NULL || root2 == NULL)
		return (root1 == root2);

	return (root1->data == root2->data) &&
	       isIdentical(root1->left, root2->left) &&
	       isIdentical(root1->right, root2->right);
}