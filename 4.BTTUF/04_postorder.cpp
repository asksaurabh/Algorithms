// https://leetcode.com/problems/binary-tree-postorder-traversal/
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

void postorderTraversal(Node* root) {
	if (root == NULL)
		return;

	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout << root->data << " ";
}

void iterativePostorder(Node *root) {
	if (root == NULL)
		return;

	stack<Node *> s;
	Node* curr = root;

	while (!s.empty() or curr != NULL) {

		if (curr) {
			s.push(curr);
			curr = curr->left;
		}

		else {
			Node* temp = s.top()->right;
			if (temp == NULL) {

				temp = s.top();
				s.pop();
				cout << temp->data << " ";

				while (!s.empty() and temp == s.top()->right) {
					temp = s.top();
					s.pop();
					cout << temp->data << " ";
				}
			}
			else {
				curr = temp;
			}
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
	root->right->right = new Node(7);

	postorderTraversal(root);
	cout << "\n";
	iterativePostorder(root);

	return 0;
}