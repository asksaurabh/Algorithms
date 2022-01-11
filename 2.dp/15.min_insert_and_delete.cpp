// Given 2 strings X and Y, find minimum number of insertions and deletions required to convert string X to string Y.

#include <iostream>
using namespace std;

int lcs(string X, string Y, int n, int m) {

	int table[n + 1][m + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {

			if (i == 0 || j == 0)
				table[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				table[i][j] = 1 + table[i - 1][j - 1];
			else
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		}
	}

	return table[n][m];
}

int minOperationsfromXtoY(string X, string Y) {

	int n = X.length();
	int m = Y.length();

	// Idea is to convert X --> LCS --> Y
	int lcsLength = lcs(X, Y, n, m);

	int numberOfDeletions = n - lcsLength;
	int numberOfInsertions = m - lcsLength;

	return numberOfInsertions + numberOfDeletions;
}

int main() {

	string X = "heap";
	string Y = "pea";

	cout << minOperationsfromXtoY(X, Y);
}