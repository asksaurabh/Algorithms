#include <bits/stdc++.h>
using namespace std;

// Returns the minimum cost of connecting all the ropes
int minimumCost(int *arr, int n) {

	// Build a min heap to select 2 ropes which have minimum len in whole stack
	priority_queue<int, vector<int>, greater<int>> minH;

	// First add all the ropes to the heap
	for (int i = 0; i < n; i++)
		minH.push(arr[i]);

	// At any time pick 2 ropes which have minimum length
	int cost = 0;
	while (minH.size() != 1) {
		int rope1 = minH.top();
		minH.pop();
		int rope2 = minH.top();
		minH.pop();

		cost += rope1 + rope2;

		// Add the newly combined rope back to be recombined
		minH.push(rope1 + rope2);
	}

	return cost;
}

int main() {

	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr) / sizeof(int);

	cout << minimumCost(arr, n);
	return 0;
}