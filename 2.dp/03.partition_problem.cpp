// https://www.geeksforgeeks.org/partition-problem-dp-18/

#include <iostream>
using namespace std;

bool isSubsetWithSumPresent(int arr[], int n, int sum) {

	int subset[n + 1][sum + 1];

	for (int i = 0; i <= n; i++) {
		subset[i][0] = true;
	}

	for (int i = 1; i <= sum; i++) {
		subset[0][i] = false;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {

			if (arr[i - 1] > j)
				subset[i][j] = subset[i - 1][j];
			else
				subset[i][j] = subset[i - 1][j] || subset[i - 1][j - arr[i - 1]];
		}
	}

	return subset[n][sum];
}

bool isPartitionPossible(int arr[], int n) {

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	if (sum % 2 != 0)
		return false;

	// If subset with sum/2 present then partition possible
	return isSubsetWithSumPresent(arr, n, sum / 2);
}

int main() {

	int arr[] = {1, 5, 11, 5};
	int n = sizeof(arr) / sizeof(int);

	cout << isPartitionPossible(arr, n);
}