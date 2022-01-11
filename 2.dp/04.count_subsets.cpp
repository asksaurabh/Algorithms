// https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/

#include <iostream>
using namespace std;

int countSubsets(int arr[], int n, int sum) {

	if (sum == 0)
		return 1;
	if (n == 0 and sum != 0)
		return 0;

	if (arr[n - 1] > sum)
		return countSubsets(arr, n - 1, sum);
	else
		return countSubsets(arr, n - 1, sum) + countSubsets(arr, n - 1, sum - arr[n - 1]);
}

int count_subsets(int arr[], int n, int sum) {

	int count[n + 1][sum + 1];

	for (int i = 0; i <= n; i++) {
		count[i][0] = 1;
	}

	for (int i = 1; i <= sum; i++) {
		count[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {

			if (arr[i - 1] > j)
				count[i][j] = count[i - 1][j];
			else
				count[i][j] = count[i - 1][j] + count[i - 1][j - arr[i - 1]];
		}
	}

	return count[n][sum];
}

int main() {

	int arr[] = {1, 2, 3, 3};
	// int arr[] = {1, 1, 1, 1};
	int n = sizeof(arr) / sizeof(int);
	int sum = 6;
	// int sum = 1;

	cout << countSubsets(arr, n, sum) << " " << count_subsets(arr, n, sum);
}