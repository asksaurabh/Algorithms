#include <bits/stdc++.h>
using namespace std;

// Check definition of nearly sorted array in question
void nearlySortedArray(int *arr, int n, int k) {

	priority_queue<int, vector<int>, greater<int>> minh;

	for (int i = 0; i < n; i++) {

		minh.push(arr[i]);
		if (minh.size() > k) {
			cout << minh.top() << " ";
			minh.pop();
		}

	}

	while (minh.size() > 0) {
		cout << minh.top() << " ";
		minh.pop();
	}
}

// Heap heapifies itself both during push and pop
// Heapify ensures that min/max element remains at the top of the heap.

int main() {

	int arr[] = {6, 5, 3, 2, 8, 10, 9};
	int n = sizeof(arr) / sizeof(int);
	int k = 3;

	nearlySortedArray(arr, n, k);
	cout << "\n" ;

	return 0;
}