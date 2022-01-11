// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
#include <iostream>
using namespace std;

int maxProfitAfterCutting(int len[], int prices[], int n, int rodLength) {

	int profit[n + 1][rodLength + 1];
	for (int i = 0; i <= n; i++)
		profit[i][0] = 0;

	for (int i = 0; i <= rodLength; i++)
		profit[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= rodLength; j++) {

			if (len[i - 1] > j)
				profit[i][j] = profit[i - 1][j];
			else
				profit[i][j] = max(profit[i - 1][j], prices[i - 1] + profit[i][j - len[i - 1]]);
		}
	}

	return profit[n][rodLength];
}

int main() {

	int len[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int prices[] = { 1, 5, 8, 9, 10, 17, 17, 20 };
	int n = sizeof(len) / sizeof(int);

	int rodLength = 8;

	cout << maxProfitAfterCutting(len, prices, n, rodLength);
}