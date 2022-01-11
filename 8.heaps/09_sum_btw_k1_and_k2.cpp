#include <bits/stdc++.h>
using namespace std;

// Find kth smallest number
int findKthSmallest(int *arr, int n, int k) {

	// Build a max heap
	priority_queue<int> maxH;

	for (int i = 0; i < n; i++) {
		maxH.push(arr[i]);

		if (maxH.size() > k)
			maxH.pop();
	}

	return maxH.top();
}

// Returns sum between k1th smallest and k2th smallest numbers
int sumBetweenk1Andk2(int *arr, int n, int k1, int k2) {

	// Find the k1th and k2th smallest number
	int num1 = findKthSmallest(arr, n, k1);
	int num2 = findKthSmallest(arr, n, k2);

	// Find sum btw num1 and num2
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > num1 and arr[i] < num2)
			sum += arr[i];
	}

	return sum;
}

int main() {

	int arr[] = {1, 3, 12, 5, 15, 11};
	int n = sizeof(arr) / sizeof(int);
	int k1 = 3, k2 = 6;

	cout << sumBetweenk1Andk2(arr, n, k1, k2);

	return 0;
}