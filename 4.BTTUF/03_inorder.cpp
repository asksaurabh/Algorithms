// https://leetcode.com/problems/binary-tree-inorder-traversal/
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

void inorderTraversal(Node* root) {
	if (root == NULL)
		return;

	inorderTraversal(root->left);
	cout << root->data << " ";
	inorderTraversal(root->right);
}

void iterativeInorder(Node *root) {
	if (root == NULL)
		return;

	stack<Node *> s;
	Node* currNode = root;

	while (true) {

		if (currNode != NULL) {
			s.push(currNode);
			currNode = currNode->left;
		}

		else {
			if (s.empty() == true)
				break;
			currNode = s.top();
			s.pop();
			cout << currNode->data << " ";
			currNode = currNode->right;
		}
	}
}

int main() {

	Node *root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);

	inorderTraversal(root);
	cout << "\n";
	iterativeInorder(root);
	return 0;
}