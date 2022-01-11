// Given a bitonic array, Find the max element in it.
// Bitonic array is one which increases monotonically and then decreases monotonically
// Observations:
// 1. n >= 3
// 2. There is always be a peak element, also the peak element can only be one such element in whole array.
// 3. Peak element can't occur on edges of array. this means mid - 1 and mid + 1 always exist.

#include <iostream>
using namespace std;

int maxInBitonicArray(int arr[], int n) {

	int start = 0;
	int end = n - 1;

	while (start <= end) {

		int mid = start + (end - start) / 2;
		// As array is always bitonic mid - 1 and mid + 1 always exist.

		if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
			return mid;
		else if (arr[mid - 1] > arr[mid])
			end = mid - 1;
		else if (arr[mid + 1] > arr[mid])
			start = mid + 1;
	}

	return -1;
}

int main() {

	int arr[] = {2, 4, 7, 8, 10, 15, 13, 11, 3, 2, 1};
	// int arr[] = {10, 30, 10};
	int n = sizeof(arr) / sizeof(int);

	cout << maxInBitonicArray(arr, n);
}