// Find the largest subarray with given sum k. Here array contains only positive integers
#include <bits/stdc++.h>
using namespace std;

int approach1(int *arr, int n, int reqSum) {

	int windowSize = -1;
	int i = 0, j = 0, currSum = 0;

	while (j < n) {

		currSum += arr[j];

		if (currSum < reqSum)
			j++;
		else if (currSum == reqSum) {
			windowSize = max(windowSize, j - i + 1);
			j++;
		}

		else if (currSum > reqSum) {

			while (currSum > reqSum) {
				currSum -= arr[i];
				i++;
			}

			if (currSum == reqSum)
				windowSize = max(windowSize, j - i + 1);

			j++;
		}
	}

	return windowSize;
}


int main() {

	int arr[] = {4, 1, 1, 1, 2, 3, 5};
	int n = sizeof(arr) / sizeof(int);
	int reqSum = 5;

	cout << approach1(arr, n, reqSum);

	return 0;
}