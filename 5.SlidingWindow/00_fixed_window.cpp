#include <bits/stdc++.h>
using namespace std;

// Approach1: The one where we use 2 loops
int approach1(int *arr, int n, int windowSize) {

	int maxSum = 0;
	for (int i = 0; i <= n - windowSize; i++) {
		int currSum = 0;
		for (int j = 0; j < windowSize; j++) {
			currSum += arr[i + j];
		}

		maxSum = max(maxSum, currSum);
	}

	return maxSum;
}

//approach2: The one where we use sliding window concept. FIXED SIZE
int approach2(int *arr, int n, int windowSize) {

	int i = 0, j = 0, currSum = 0, maxSum = 0;

	while (j < n) {

		currSum += arr[j];

		if (j - i + 1 < windowSize)
			j++;

		else {
			maxSum = max(maxSum, currSum);
			currSum -= arr[i];
			i++; j++;
		}
	}

	return maxSum;
}

int main() {

	int arr[] = {2, 3, 5, 2, 9, 7, 1};
	int n = sizeof(arr) / sizeof(int);

	int windowSize = 3;

	cout << approach1(arr, n, windowSize) << " " << approach2(arr, n, windowSize);
	return 0;
}