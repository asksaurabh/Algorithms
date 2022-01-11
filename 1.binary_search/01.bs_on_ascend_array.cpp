// Given an array sorted in ascending order and an element to search in the array. Find the index of the searched key in the array. If not present return -1;

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
			start = mid + 1;
		else
			end = mid - 1;
	}

	return -1;
}

int main() {

	int arr[] = {1, 3, 5, 7, 8, 10, 12, 14, 17};
	int n = sizeof(arr) / sizeof(int);
	int key = 10;

	cout << isKeyPresent(arr, n, key);
}