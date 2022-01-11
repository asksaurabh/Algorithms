// Given an array and a difference. Find the count of the number of subsets with a given difference.
// Meaning S1 - S2 == diff (How many such subsets are possible).

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

			if (arr[i - 1] > j)
				table[i][j] = table[i - 1][j];
			else
				table[i][j] = table[i - 1][j] + table[i - 1][j - arr[i - 1]];
		}
	}

	return table[n][sum];
}


int countSubsetsWithGivenDifference(int arr[], int n, int diff) {

	int arr_sum = 0;
	for (int i = 0; i < n; i++)
		arr_sum += arr[i];

	// All I have to do is to find the count of all those subsets whose sum is
	int sum = (arr_sum + diff) / 2;

	return countSubsetsWithGivenSum(arr, n, sum);
}

int main() {

	int arr[] = {1, 1, 2, 3};
	int n = sizeof(arr) / sizeof(int);
	int diff = 1;

	cout << countSubsetsWithGivenDifference(arr, n, diff);
}