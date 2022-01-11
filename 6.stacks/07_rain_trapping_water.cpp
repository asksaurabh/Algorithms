// rain Water Trapping
#include <bits/stdc++.h>
using namespace std;

int approach1(int *arr, int n) {

	int left[n], right[n];
	left[0] = arr[0];

	for (int i = 1; i < n; i++)
		left[i] = max(left[i - 1], arr[i]);

	right[n - 1] = arr[n - 1];

	for (int i = n - 2; i >= 0; i--)
		right[i] = max(right[i + 1], arr[i]);

	int waterTrapped = 0;
	for (int i = 0; i < n; i++) {
		waterTrapped += min(left[i], right[i]) - arr[i];
	}

	return waterTrapped;
}

int main() {

	int arr[] = {3, 0, 0, 2, 0, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << approach1(arr, n);
	return 0;
}