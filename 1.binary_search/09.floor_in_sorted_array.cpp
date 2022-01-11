// Find the floor of an element(key) in the sorted array.

#include <iostream>
using namespace std;

int floorInSortedArray(int arr[], int n, int key) {

	int start = 0;
	int end = n - 1;
	int res = -1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key)
			return mid;

		else if (arr[mid] < key) {
			// Possible candidate
			res = mid;
			start = mid + 1;
		}

		else
			end = mid - 1;
	}

	return res;
}

int main() {

	int arr[] = {5, 6, 8, 9, 10, 15, 18, 20};
	int n = sizeof(arr) / sizeof(int);

	// int key = 7;
	int key = 2;

	cout << floorInSortedArray(arr, n, key);
}