// Min Heap is:
// 1. Complete Binary Tree (Means array representation possible)
// 2. Every node has value smaller than its descendents.

#include <bits/stdc++.h>
using namespace std;

class MinHeap {
private:
	int *arr;
	int size;
	int capacity;
public:
	MinHeap(int capacity) {
		arr = new int[capacity];
		size = 0;
		this->capacity = capacity;
	}

	int getLeftChild(int pos);
	int getRightChild(int pos);
	int getParent(int pos);
	void insert(int key);
	void printMinHeap();
	void minHeapify(int pos);
	int getMinimum();
	int extractMinimum();
	void decreaseKey(int pos, int key);
	void deleteKey(int pos);
	void buildMinHeap();
};

int MinHeap::getLeftChild(int pos) {
	return (2 * pos + 1);
}
int MinHeap::getRightChild(int pos) {
	return (2 * pos + 2);
}
int MinHeap::getParent(int pos) {
	return (pos - 1) / 2;
}
void MinHeap::printMinHeap() {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";
}
int MinHeap::getMinimum() {
	if (size == 0) return INT_MAX;
	return arr[0];
}

// T.C -> O(log(size))
void MinHeap::insert(int key) {
	if (size == capacity) return;

	// Insert at the last position
	size++;
	arr[size - 1] = key;

	// Now make it follow minHeap property
	int i = size - 1;                                 // Curr position of key
	while (i > 0 and arr[getParent(i)] > arr[i]) {
		swap(arr[getParent(i)], arr[i]);
		i = getParent(i);
	}
}

// Given a node pos which may be violating the min heap property, fix it.
// Assume rest of the minHeap is fine except the given pos.
// T.C -> O(log(n)), S.C -> O(logn) if root is faulty and has max value in whole heap.
void MinHeap::minHeapify(int pos) {
	int left = getLeftChild(pos);
	int right = getRightChild(pos);
	int smallest = pos;

	// Find which pos contains the key with lowest val: pos,left,right
	if (left < size and arr[left] < arr[pos]) {
		smallest = left;
	}
	if (right < size and arr[right] < arr[smallest]) {
		smallest = right;
	}

	if (smallest != pos) {
		swap(arr[pos], arr[smallest]);
		minHeapify(smallest);
	}
}

// Removes the minimum element from the heap and returns it.
// t.C -> O(log(n))
int MinHeap::extractMinimum() {
	if (size == 0) return INT_MAX;
	if (size == 1) {
		size--;
		return arr[0];
	}

	int res = arr[0];
	swap(arr[0], arr[size - 1]);
	size--;         // Delete

	// Now root contains invalid/faulty value. So, make it follow minHeap prop.
	minHeapify(0);
	return res;
}

// Given a pos and a key, update that pos with given key and make sure it still remains minHeap
// T.C -> O(logn)
void MinHeap::decreaseKey(int pos, int key) {
	if (pos >= size) return;

	arr[pos] = key;

	// Now do something like insert
	int i = pos;
	while (i > 0 and arr[getParent(i)] > arr[i]) {
		swap(arr[i], arr[getParent(i)]);
		i = getParent(i);
	}
}

// Deletes the key at given pos and make sure that it still remains minHeap
void MinHeap::deleteKey(int pos) {
	if (pos >= size) return;

	// Place lowest val at that index possible and make it reach the top.
	decreaseKey(pos, INT_MIN);

	// Now INT_MIN is at top. So extract it.
	extractMinimum();
}

// Given a random arr, rearrange it such that it becomes a min heap.
// T.C -> O(n). LOOK COPY FOR PROOF.
void MinHeap::buildMinHeap() {
	if (size == 0) return;

	// Start from bottom most rightmost internal node
	// How do I find that?
	// Bottom most right most internal node -> Parent of last node.
	for (int i = (size - 1 - 1) / 2; i >= 0; i--) {
		minHeapify(i);
	}
}

int main() {

	///////////////// GIVEN //////////////////
	vector<int> keys = {10, 20, 15, 40, 50, 100, 25, 45};

	MinHeap minH(15);
	for (int key : keys) {
		minH.insert(key);
	}
	//////////////////////////////////////////

	/////////////// TO IMPLEMENT /////////////

	// minH.insert(12);
	// minH.printMinHeap();

	// minH.minHeapify(0);
	// minH.printMinHeap();

	// cout << minH.extractMinimum() << "\n";
	// minH.printMinHeap();

	minH.printMinHeap();
	minH.decreaseKey(7, 5);
	minH.printMinHeap();

	minH.deleteKey(2);
	minH.printMinHeap();
	return 0;
}