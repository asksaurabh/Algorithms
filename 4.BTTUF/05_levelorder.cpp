// https://leetcode.com/problems/binary-tree-level-order-traversal/
#include <iostream>
#include <queue>
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

void levelorderTraversal(Node* root) {
	if (root == NULL)
		return;

	queue<Node *> q;
	q.push(root);

	while (!q.empty()) {
		Node* curr_node = q.front();
		q.pop();
		cout << curr_node->data << " ";

		if (curr_node->left != NULL) {
			q.push(curr_node->left);
		}

		if (curr_node->right != NULL)
			q.push(curr_node->right);
	}

}

int main() {

	Node *root = new Node(1);

	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);

	levelorderTraversal(root);
	return 0;
}