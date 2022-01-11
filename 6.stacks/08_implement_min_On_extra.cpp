// Implement a stack that supports push, pop and getMinelement() which returns the minimum element in the stack in O(1) time.
#include <bits/stdc++.h>
using namespace std;

stack<int> s;
stack<int> ss;         // Used for getting min element in O(1) time

void insert(int element) {

	s.push(element);

	if (ss.empty() || ss.top() >= element)
		ss.push(element);
}

void del() {

	if (s.empty())
		return;

	int poppedElement = s.top();
	s.pop();

	// Update minimum if :
	if (ss.top() == poppedElement)
		ss.pop();
}

int getMinimum() {

	if (ss.empty())
		return -1;

	return ss.top();
}

int main() {

	insert(18);
	cout << getMinimum() << endl;

	insert(19);
	cout << getMinimum() << endl;

	insert(29);
	cout << getMinimum() << endl;

	insert(15);
	cout << getMinimum() << endl;

	insert(16);
	cout << getMinimum() << endl;

	del();
	cout << getMinimum() << endl;

	del();
	cout << getMinimum() << endl;

	return 0;
}