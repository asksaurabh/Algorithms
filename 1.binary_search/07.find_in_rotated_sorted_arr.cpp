// Given an array which was originally sorteed but now it is rotated(anti clockwise) and a key to be searched in it. FInd the element if present else return -1;

#include <iostream>
using namespace std;

int findMinElementIndex(int arr[], int n) {

	int start = 0;
	int end = n - 1;

	while (start <= end) {

		if (arr[start] <= arr[end])
			return start;

		int mid = start + (end - start) / 2;
		int next = (mid + 1) % n;
		int prev = (mid - 1 + n) % n;

		if (arr[mid] <= arr[prev] and arr[mid] <= arr[next]) {
			// mid is the smallest element
			return mid;
		}

		else if (arr[start] <= arr[mid]) {
			// Part 1 is sorted and Part 2 is unsorted. Move to part 2
			start = mid + 1;
		}

		else if (arr[mid] <= arr[end]) {
			// Part 2 is sorted and Part 1 is unsorted. Move to part 1
			end = mid - 1;
		}
	}

	return -1;
}

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

int findKeyInSortedRotatedArray(int arr[], int minElementIndex, int size, int key) {

	// Treating minElement as the pivot

	// Finding key before the min element
	int part1 = binarySearch(arr, 0, minElementIndex - 1, key);

	// Finding key after the min element
	int part2 = binarySearch(arr, minElementIndex, size - 1, key);

	if (part1 == -1 and part2 == -1)
		return -1;

	if (part1 == -1)
		return part2;
	else
		return part1;
}

int main() {

	// int arr[] = {10, 12, 14, 17, 19, 1, 2, 4};
	int arr[] = {3, 1};
	int n = sizeof(arr) / sizeof(int);
	// int key = 19;
	int key = 0;

	int minElementIndex = findMinElementIndex(arr, n);

	cout << findKeyInSortedRotatedArray(arr, minElementIndex, n, key);
}