#include <iostream>
using namespace std;

int lowerBound(int coins[], int start, int end, int key) {

	int res = -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (coins[mid] == key)
			return coins[mid];

		else if (coins[mid] < key) {
			res = mid;
			start = mid + 1;
		}

		else
			end = mid - 1;
	}

	return coins[res];
}

int minCoinsForMakingChange(int coins[], int n, int money) {

	int countCoins = 0;
	while (money > 0) {
		int currDenomination = lowerBound(coins, 0, n - 1, money);
		money -= currDenomination;

		countCoins++;
	}

	return countCoins;
}

int main() {

	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int n = sizeof(coins) / sizeof(int);

	int money = 39;

	cout << minCoinsForMakingChange(coins, n, money);

	return 0;
}