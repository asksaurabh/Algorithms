// Given a nearly sorted array in which element at ith index can be at i-1, i, i+1 th index. Find a given element in this array.

#include <iostream>
using namespace std;

int findInNearlySortedArray(int arr[], int n, int key) {

	int start = 0;
	int end = n - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == key)
			return mid;
		if (mid - 1 >= start and arr[mid - 1] == key)
			return mid - 1;
		if (mid + 1 <= end and arr[mid + 1] == key)
			return mid + 1;

		else if (arr[mid] < key)
			start = mid + 2;
		else
			end = mid - 2;
	}

	return -1;
}

int main() {
	int arr[] = {1, 3, 2, 4, 5, 6, 8, 7, 9};

	// arr[] = {1,2,3,4,5,6,7,8,9};

	int n = sizeof(arr) / sizeof(int);
	int key = 0;

	cout << findInNearlySortedArray(arr, n, key);
}