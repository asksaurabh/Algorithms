// GIven an infinitely sorted array. Find a given element in the array

#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int key) {

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

int searchInInfinitelySortedArray(int arr[], int n, int key) {

	// FInding the right space
	int start = 0;
	int end = 1;

	while (key > arr[end]) {
		start = end;
		end = end * 2;
	}

	// Searching in the found space
	return binarySearch(arr, start, end, key);
}