// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
// Empty subset is also a test case.

#include <iostream>
using namespace std;

bool isSubsetWithSumPresent(int arr[], int n, int sum) {

	if (sum == 0)
		return true;
	if (n == 0 and sum != 0)
		return false;

	if (arr[n - 1] > sum)
		return isSubsetWithSumPresent(arr, n - 1, sum);
	else
		return isSubsetWithSumPresent(arr, n - 1, sum) || isSubsetWithSumPresent(arr, n - 1, sum - arr[n - 1]);
}

bool isSubsetSumPresent(int arr[], int n, int sum) {

	bool subset[n + 1][sum + 1];

	for (int i = 0; i <= n; i++) {
		// if sum == 0 then there is always a null subset u can choose
		subset[i][0] = true;
	}

	for (int i = 1; i <= sum; i++) {
		// If sum is not 0 and there are no elements left
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

int main() {

	int arr[] = {3, 34, 4, 12, 5, 2};
	int n = sizeof(arr) / sizeof(int);
	int sum = 9;
	// int sum = 100;

	cout << isSubsetWithSumPresent(arr, n, sum) << " " << isSubsetSumPresent(arr, n, sum);
}