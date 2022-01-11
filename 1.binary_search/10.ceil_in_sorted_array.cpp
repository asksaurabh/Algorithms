// Find the ceil of an element(key) in the SORTED array.

#include <iostream>
using namespace std;

int ceilInSortedArray(int arr[], int n, int key) {

	int start = 0;
	int end = n - 1;
	int res = n - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key)
			return mid;

		else if (arr[mid] > key) {
			// possible candidate
			res = mid;
			end = mid - 1;
		}

		else
			start = mid + 1;
	}

	return res;
}

int main() {

	int arr[] = {5, 6, 8, 9, 10, 15, 18, 20};
	int n = sizeof(arr) / sizeof(int);

	int key = 7;
	// int key = 22;
	// int key = 0;
	// int key = 6;

	cout << ceilInSortedArray(arr, n, key);
}