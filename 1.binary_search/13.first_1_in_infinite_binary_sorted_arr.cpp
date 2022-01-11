// Find the index of the 1st 1 in the infinite binary sorted array

// infinite + 1st occ

#include <iostream>
using namespace std;

int firstOccOf1(int arr[], int start, int end, int key) {

	int res = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key) {
			res = mid;
			end = mid - 1;
		}

		else if (arr[mid] < key)
			start = mid + 1;

		else
			end = mid - 1;
	}

	return res;
}

int indexOfFirst1InInfiniteBinarySortedArray(int arr[], int n, int key) {

	int start = 0;
	int end = 1;

	while (key > arr[mid]) {
		start = end;
		end = end * 2;
	}

	return firstOccOf1(arr, start, end, key);
}