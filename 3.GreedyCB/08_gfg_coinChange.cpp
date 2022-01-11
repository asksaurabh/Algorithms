#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int minCoins(int coins[], int n, int money) {

	sort(coins, coins + n, greater<int>());
	int result = 0;

	for (int i = 0; i < n; i++) {

		if (coins[i] <= money) {
			int coinContribution = floor(money / coins[i]);
			result += coinContribution;
			money = money - coinContribution * coins[i];
		}

		if (money == 0)
			break;
	}

	return result;
}

int main() {
	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int n = sizeof(coins) / sizeof(int);

	int money = 39;
	cout << minCoins(coins, n, money);
}