// GIven a soretd array and a key, find the element in the array whose abosulte difference with the key is minimum
#include <iostream>
using namespace std;

int minimumDifferenceElement(int arr[], int n, int key) {

	int start = 0;
	int end = n - 1;
	int res;

	while (start <= end) {

		int mid = start + (end - start) / 2;
		if (arr[mid] == key)
			return mid;

		else if (arr[mid] < key)
			start = mid + 1;

		else
			end = mid - 1;
	}

	// Coming here means key is not present in the array
	// Now end points to -> floor(key), start points to -> ceil(key)
	// Every key will have either floor or ceil or both.

	if (end < 0) {
		// Means key has no floor, so minimum difference will be with ceil(key)
		return start;
	}

	else if (start > n - 1) {
		// Means key has no ceil, so minimum difference will be with floor(key)
		return end;
	}

	else {
		// both floor and ceil present
		res = abs(key - arr[start]) > abs(key - arr[end]) ? end : start;
	}

	return res;
}

int main() {

	int arr[] = {2, 3, 5, 8, 10, 15};
	int n = sizeof(arr) / sizeof(int);

	int key = 12;
	// int key = 8;
	// int key = 18;
	// int key = 1;

	cout << minimumDifferenceElement(arr, n, key);
}