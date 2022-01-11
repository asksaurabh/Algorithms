// Given a sorted array. Find the count of key element in it.

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

int countOcc(int arr[], int n, int key) {

	int first_occ = firstOccurence(arr, n, key);
	int last_occ = lastOccurence(arr, n, key);

	if (first_occ == -1 and last_occ == -1)
		return 0;
	if (first_occ == -1 || last_occ == -1)
		return 1;

	return (last_occ - first_occ + 1);
}

int main() {

	int arr[] = {2, 4, 4, 10, 10, 10, 14, 19};
	int n = sizeof(arr) / sizeof(int);

	// int key = 20;
	// int key = 10;
	// int key = 4;
	int key = 19;
	cout << "Count of " << key << ": " << countOcc(arr, n, key) << endl;

}