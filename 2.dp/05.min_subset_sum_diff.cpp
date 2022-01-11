// https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<bool> subsetSum(int arr[], int n, int sum) {

	bool table[n + 1][sum + 1];

	for (int i = 0; i <= n; i++)
		table[i][0] = true;

	for (int i = 1; i <= sum; i++)
		table[0][i] = false;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {

			if (arr[i - 1] > j)
				table[i][j] = table[i - 1][j];
			else
				table[i][j] = table[i - 1][j] || table[i - 1][j - arr[i - 1]];
		}
	}

	vector<bool> possibleCandidates;
	for (int i = 0; i <= sum / 2; i++) {
		possibleCandidates.push_back(table[n][i]);
	}

	return possibleCandidates;
}


int minSubsetSumDifference(int arr[], int n) {

	// Find the range
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	// Find the possible candidate subsets
	vector<bool> subset = subsetSum(arr, n, sum);

	// Minimize the difference (range - 2*S1)
	int mn = INT_MAX;
	for (int i = 0; i < subset.size(); i++) {
		if (subset[i] == true)
			mn = min(mn, sum - 2 * i);
	}

	return mn;
}

int main() {

	int arr[] = {1, 2, 7};
	int n = sizeof(arr) / sizeof(int);

	cout << minSubsetSumDifference(arr, n);
}