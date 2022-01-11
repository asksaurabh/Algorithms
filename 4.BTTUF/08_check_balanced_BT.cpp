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

int maxHeight(Node* root) {
	if (root == NULL)
		return 0;

	int lh = maxHeight(root->left);
	int rh = maxHeight(root->right);

	return max(lh, rh) + 1;
}

bool naiveCheckBalancedBT(Node* root) {
	if (root == NULL)
		return true;

	int lh = maxHeight(root->left);
	int rh = maxHeight(root->right);

	if (abs(lh - rh) > 1)
		return -1;

	bool checkLeft = naiveCheckBalancedBT(root->left);
	if (checkLeft == false)
		return false;

	bool checkRight = naiveCheckBalancedBT(root->right);
	if (checkRight == false)
		return false;

	return true;
}

// Optimised approach:
// Returns maxHeight if balanced otherwise -1
int optimisedBalancedBT(Node* root) {
	if (root == NULL)
		return 0;

	int lh = optimisedBalancedBT(root->left);
	if (lh == -1)
		return -1;
	int rh = optimisedBalancedBT(root->right);
	if (rh == -1)
		return -1;

	if (abs(lh - rh) > 1)
		return -1;

	return max(lh, rh) + 1;
}

int main() {

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	cout << naiveCheckBalancedBT(root) << " " << optimisedBalancedBT(root);
	return 0;
}