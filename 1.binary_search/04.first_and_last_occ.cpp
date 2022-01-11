// Given an array sorted in ascending order and an element to search in the array(contains dups). Find the first and last occurence of the searched key. If not present return -1;

#include <iostream>
using namespace std;

int firstOccurence(int arr[], int n, int key) {

	int start = 0;
	int end = n - 1;
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

int lastOccurence(int arr[], int n, int key) {

	int start = 0;
	int end = n - 1;
	int res = -1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key) {
			res = mid;
			start = mid + 1;
		}

		else if (arr[mid] < key)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return res;
}

int main() {

	int arr[] = {2, 4, 10, 10, 10, 14, 19};
	int n = sizeof(arr) / sizeof(int);

	int key = 10;

	cout << firstOccurence(arr, n, key) << endl;
	cout << lastOccurence(arr, n, key) << endl;
}