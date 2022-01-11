#include <iostream>
#include <stack>
#include <queue>
#include <vector>
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

void allInOneTraversal(Node* root) {
	if (root == NULL)
		return;

	vector<int> pre, in, post;

	// Here comes the sexy part
	stack<pair<Node*, int>> s;
	s.push({root, 1});

	while (!s.empty()) {

		auto it = s.top();
		s.pop();

		if (it.second == 1) {
			pre.push_back(it.first->data);
			it.second++;
			s.push(it);

			if (it.first->left)
				s.push({it.first->left, 1});
		}

		else if (it.second == 2) {
			in.push_back(it.first->data);
			it.second++;
			s.push(it);

			if (it.first->right)
				s.push({it.first->right, 1});
		}

		else
			post.push_back(it.first->data);
	}

	cout << "\nPreorder: ";
	for (int val : pre)
		cout << val << " ";

	cout << "\nInorder: ";
	for (int val : in)
		cout << val << " ";

	cout << "\nPostorder: ";
	for (int val : post)
		cout << val << " ";

}

void level(Node* root) {
	queue<Node*> q;
	q.push(root);

	if (root == NULL)
		return;

	while (!q.empty()) {

		int currLevelSize = q.size();

		for (int i = 0; i < currLevelSize; i++) {
			Node* currNode = q.front();
			q.pop();
			cout << currNode->data << " ";

			if (currNode->left != NULL)
				q.push(currNode->left);
			if (currNode->right != NULL)
				q.push(currNode->right);
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

	cout << "Level: ";
	level(root);

	allInOneTraversal(root);
	return 0;
}