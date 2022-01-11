// Given an array sorted in descending order and an element to search in the array. Find the index of the searched key in the array. If not present return -1;

#include <iostream>
using namespace std;

int isKeyPresent(int arr[], int n, int key) {

	int start = 0;
	int end = n - 1;

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

int main() {

	int arr[] = {18, 17, 14, 12, 8, 5, 3, 2, 1};
	int n = sizeof(arr) / sizeof(int);
	int key = 1;

	cout << isKeyPresent(arr, n, key);
}