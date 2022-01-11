// https://leetcode.com/problems/binary-tree-preorder-traversal
#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		this->left = this->right = NULL;
	}
};

void preorderTraversal(Node* root) {
	if (root == NULL)
		return;

	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void iterativePreorder(Node *root) {
	if (root == NULL)
		return;

	stack<Node *> s;
	s.push(root);

	while (!s.empty()) {
		Node* currNode = s.top();
		s.pop();

		cout << currNode->data << " ";
		if (currNode->right != NULL)
			s.push(currNode->right);
		if (currNode->left != NULL)
			s.push(currNode->left);
	}

}

int main() {

	Node *root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);

	preorderTraversal(root);
	cout << "\n";
	iterativePreorder(root);
	return 0;
}