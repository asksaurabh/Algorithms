// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

#include <iostream>
using namespace std;

int knapSack(int W, int wt[], int val[], int n) {

	if (n == 0 || W == 0)
		return 0;

	// If current element is not possible to include
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	else
		return max(knapSack(W, wt, val, n - 1), val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1));
}

int knapSackBottomUp(int W, int wt[], int val[], int n) {

	int maxValue[n + 1][W + 1];

	for (int i = 0; i <= W; i++) {
		maxValue[0][i] = 0;
	}

	for (int i = 0; i <= n; i++) {
		maxValue[i][0] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {

			if (wt[i - 1] > j) {
				maxValue[i][j] = maxValue[i - 1][j];
			}
			else {
				maxValue[i][j] = max(maxValue[i - 1][j], val[i - 1] + maxValue[i - 1][j - wt[i - 1]]);
			}

		}
	}

	return maxValue[n][W];
}

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);

	cout << knapSack(W, wt, val, n) << endl;
	cout << knapSackBottomUp(W, wt, val, n) << endl;
	return 0;
}