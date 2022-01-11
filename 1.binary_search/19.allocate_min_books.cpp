// Given the array of books with pages and the number of students, allocate minimum number of max pages that can be given to each student so that there stress is less. This array can be unsorted.
// 1. Books are to be given as a whole to each student.
// 2. Atleast 1 book should be allocated to each student.
// 3. Books allocated should be continuous.

#include <iostream>
using namespace std;

int maxPagesInArray(int arr[], int n) {
	int maxi = arr[0];
	for (int i = 1; i < n; i++)
		maxi = max(arr[i], maxi);

	return maxi;
}

int sumOfAllPages(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	return sum;
}

bool isValid(int arr[], int n, int maxPages, int total_students) {

	int curr_students = 1;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		sum += arr[i];

		if (sum > maxPages) {
			curr_students++;
			sum = arr[i];       // Shift to new student with current pages
		}

		if (curr_students > total_students)
			return false;
	}

	return true;
}

int minimumMaxPages(int arr[], int n, int students) {

	int start = maxPagesInArray(arr, n);
	int end = sumOfAllPages(arr, n);
	int res = -1;

	while (start <= end) {

		int mid = start + (end - start) / 2;

		if (isValid(arr, n, mid, students) == true) {
			res = mid;
			end = mid - 1;
		}

		else
			start = mid + 1;
	}

	return res;
}

int main() {

	int arr[] = {10, 20, 30, 40};
	int n = sizeof(arr) / sizeof(int);
	int students = 2;

	cout << minimumMaxPages(arr, n, students);
}