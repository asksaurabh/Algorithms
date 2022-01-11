// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

#include <iostream>
#include <climits>
using namespace std;

int solve(int arr[], int i, int j) {

	if (i == j)
		return 0;

	int res = INT_MAX;

	for (int k = i; k <= j - 1; k++) {
		int tempAns = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		res = min(res, tempAns);
	}

	return res;
}

int main() {

	int arr[] = {40, 20, 30, 10, 30};
	// int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	int i = 1;
	int j = n - 1;
	cout << solve(arr, i, j);
}