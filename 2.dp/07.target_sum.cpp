// https://leetcode.com/problems/target-sum/

#include <iostream>
using namespace std;

int countSubsetsWithGivenSum(int arr[], int n, int sum) {

	int table[n + 1][sum + 1];
	for (int i = 0; i <= n; i++)
		table[i][0] = 1;

	for (int i = 1; i <= sum; i++)
		table[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {

			// if zeros's are there ignore as -0 or +0 are not different
			if (arr[i - 1] == 0)
				table[i][j] = table[i - 1][j];
			else if (arr[i - 1] > j)
				table[i][j] = table[i - 1][j];
			else
				table[i][j] = table[i - 1][j] + table[i - 1][j - arr[i - 1]];
		}
	}

	return table[n][sum];
}

int countSubsetsWithGivenTargetSum(int arr[], int n, int sum) {

	int arr_sum = 0;
	for (int i = 0; i < n; i++)
		arr_sum += arr[i];

	// Here sum is desguised as diff
	int res_sum = (sum + arr_sum) / 2;

	return countSubsetsWithGivenSum(arr, n, res_sum);
}

int main() {

	// int arr[] = {1, 1, 2, 3};
	int arr[] = {0, 0, 1};
	int target_sum = 1;
	int n = sizeof(arr) / sizeof(int);

	cout << countSubsetsWithGivenTargetSum(arr, n, target_sum);
}