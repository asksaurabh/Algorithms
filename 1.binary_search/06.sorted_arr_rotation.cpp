// Given an array which was originally sorteed but now it is rotated(anti clockwise). Find the number of times the original array was rotated.
#include <iostream>
using namespace std;

int countRotation(int arr[], int n) {

	// Goal is to find the minimum element.
	// As in original array pos of min ele is 0. In the Ip array
	// pos of min ele will decide times of rotation (pos of min ele in rotated array)

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

int main() {

	int arr[] = {10, 12, 14, 17, 19, 1, 2, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << countRotation(arr, n);
}