#include <iostream>
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

// Naive Approach:
int maxHeight(Node* root) {
	if (root == NULL)
		return 0;

	int lh = maxHeight(root->left);
	int rh = maxHeight(root->right);

	return max(lh, rh) + 1;
}

void diameterUtil(Node* node, int &diameter) {
	if (node == NULL)
		return;

	// While standing at the current node
	int lh = maxHeight(node->left);
	int rh = maxHeight(node->right);

	// COmpute the diameter
	diameter = max(diameter, lh + rh);

	// Recursively call for left and right subtree
	diameterUtil(node->left, diameter);
	diameterUtil(node->right, diameter);
}

int maxDiameter(Node* root) {
	int diameter = 0;
	diameterUtil(root, diameter);
	return diameter;
}

//Better Approach: Identify the repetitive work
int height(Node* root, int &diameter) {
	if (root == NULL)
		return 0;

	int lh = height(root->left, diameter);
	int rh = height(root->right, diameter);

	diameter = max(diameter, lh + rh);

	return 1 + max(lh, rh);
}

int maxDiameterBetter(Node* root) {
	int diameter = 0;
	height(root, diameter);
	return diameter;
}

int main() {

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	cout << maxDiameter(root) << " " << maxDiameterBetter(root);
	return 0;
}