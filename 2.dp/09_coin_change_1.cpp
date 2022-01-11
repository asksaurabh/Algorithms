// Count the total number of ways in which u can reach sum by adding given coins in your bag. Coins have unlimited supply

#include <iostream>
using namespace std;

int totalWays(int coins[], int n, int sum) {

	int count[n + 1][sum + 1];
	for (int i = 0; i <= n; i++)
		count[i][0] = 1;

	for (int i = 1; i <= sum; i++)
		count[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= sum; j++) {

			if (coins[i - 1] > j)
				count[i][j] = count[i - 1][j];
			else
				count[i][j] = count[i - 1][j] + count[i][j - coins[i - 1]];
		}
	}

	return count[n][sum];
}


int main() {

	int coins[] = {1, 2, 3};
	int n = sizeof(coins) / sizeof(int);

	int sum = 5;

	cout << totalWays(coins, n, sum);
}