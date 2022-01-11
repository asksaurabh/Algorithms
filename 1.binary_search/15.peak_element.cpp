// Given an unsorted array, find the peak element in it. Peak element is defined as the element that is greater than its two neighbours. In case of multiple peak elements return any one of them.

#include <iostream>
using namespace std;

int peakElement(int arr[], int n) {

	int start = 0;
	int end = n - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (mid > 0 and mid < n - 1) {
			// Means mid-1 and mid+1 exist
			if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
				return mid;
			else if (arr[mid - 1] > arr[mid])
				end = mid - 1;
			else if (arr[mid + 1] > arr[mid])
				start = mid + 1;
		}

		else if (mid == 0) {
			if (arr[mid] > arr[1])
				return mid;
			else
				return 1;
		}

		else if (mid == n - 1) {
			if (arr[mid] > arr[n - 2])
				return mid;
			else
				return n - 2;
		}
	}

	return -1;
}

int main() {

	int arr[] = {2, 4, 3, 16, 20, 15, 8};
	// int arr[] = {10, 20};
	// int arr[] = {30, 10};
	// int arr[] = {1, 2, 3, 4, 5};
	// int arr[] = {5, 4, 3, 2, 1};
	// int arr[] = {30, 10, 5, 4, 6, 40};

	int n = sizeof(arr) / sizeof(int);

	cout << peakElement(arr, n);
}