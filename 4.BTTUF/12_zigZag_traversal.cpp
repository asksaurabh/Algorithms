#include <iostream>
#include <vector>
#include <queue>
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

void zigzagTraversal(Node* root) {

	vector<vector<int>> result;
	if (root == NULL)
		return;

	queue<Node*> q;
	q.push(root);
	bool leftToRight = true;

	while (!q.empty()) {

		int size = q.size();
		vector<int> currLevel(size);

		for (int i = 0; i < size; i++) {

			Node* currNode = q.front();
			q.pop();

			// Find the index for the curr node
			int index = (leftToRight == true) ? i : size - i - 1;
			currLevel[index] = currNode->data;

			if (currNode->left)
				q.push(currNode->left);
			if (currNode->right)
				q.push(currNode->right);
		}

		// make sure to flip the level for the next level
		leftToRight = !leftToRight;
		result.push_back(currLevel);
	}



	// Print the traversal
	for (auto &level : result) {
		for (int data : level) {
			cout << data << " ";
		}
		cout << "\n";
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

	zigzagTraversal(root);
	return 0;
}