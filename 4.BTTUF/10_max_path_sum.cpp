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

// Considering the all possible 4 paths

int maxSum(Node* root, int &result) {
	if (root == NULL)
		return 0;

	int leftSum = maxSum(root->left, result);
	int rightSum = maxSum(root->right, result);

	// Ensuring the path survives
	int max_single = max(max(leftSum, rightSum) + root->data, root->data);

	// What if the path ends here
	int max_top = max(max_single, leftSum + rightSum + root->data);

	// Set result
	result = max(result, max_top);

	// For further calculation with the ancestors pass the path survival sum
	return max_single;
}

int maxPathSum(Node* root) {
	int sum = INT_MIN;
	maxSum(root, sum);
	return sum;
}

int main() {

	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	cout << maxPathSum(root);
	return 0;
}