// Find the minimum number of coins required to reach sum

#include <iostream>
#include <climits>
using namespace std;

int minimumCoins(int coins[], int n, int sum) {

	int count[n + 1][sum + 1];

	for (int i = 1; i <= n; i++) {
		// minimum coins required to reach sum zero is 0
		count[i][0] = 0;
	}

	for (int i = 0; i <= sum; i++) {
		// minimum coins required when there are no coins is infinite
		count[0][i] = INT_MAX - 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {
			if (coins[i - 1] > j)
				count[i][j] = count[i - 1][j];
			else
				count[i][j] = min(count[i - 1][j], 1 + count[i][j - coins[i - 1]]);
		}
	}

	return count[n][sum];
}

int main() {
	int coins[] = {1, 2, 3};
	int n = sizeof(coins) / sizeof(int);

	int sum = 5;

	cout << minimumCoins(coins, n, sum);
}