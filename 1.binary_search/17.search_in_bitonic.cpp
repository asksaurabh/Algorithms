// Given a bitonic array, search a key in it.
// Observations:
// 1. Find peak. Call increasing BS in part1 and decreasing BS in part2

#include <iostream>
using namespace std;

int maxInBitonicArray(int arr[], int n) {

	int start = 0;
	int end = n - 1;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (arr[mid] > arr[mid - 1] and arr[mid] > arr[mid + 1])
			return mid;
		else if (arr[mid - 1] > arr[mid])
			end = mid - 1;
		else if (arr[mid + 1] > arr[mid])
			start = mid + 1;
	}

	return -1;
}

int increasingBinarySearch(int *arr, int start, int end, int key) {

	while (start <= end) {

		int mid = start + (end - start) / 2;
		if (arr[mid] == key)
			return mid;

		else if (arr[mid] < key)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return -1;
}

int decreasingBinarySearch(int *arr, int start, int end, int key) {

	while (start <= end) {

		int mid = start + (end - start) / 2;
		if (arr[mid] == key)
			return mid;

		else if (arr[mid] < key)
			end = mid - 1;
		else
			start = mid + 1;
	}

	return -1;
}

int searchInBitonicArray(int arr[], int n, int key) {

	int peakElement = maxInBitonicArray(arr, n);

	int res1 = increasingBinarySearch(arr, 0, peakElement, key);
	int res2 = decreasingBinarySearch(arr, peakElement + 1, n - 1, key);

	if (res1 == -1) return res2;
	if (res2 == -1) return res1;

	return -1;
}

int main() {

	int arr[] = {1, 3, 5, 10, 4, 2};
	// int arr[] = {1, 3, 4, 5, 10, 5, 2};

	int key = 4;
	// int key = 20;
	// int key = 0;
	int n = sizeof(arr) / sizeof(int);

	cout << searchInBitonicArray(arr, n, key);
}