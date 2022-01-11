// Given a string X, find the minimum number of deletions required to make the string palindrome

#include <iostream>
using namespace std;

int lps(string X) {

	string Y = "";
	for (int i = X.length() - 1; i >= 0; i--)
		Y.push_back(X[i]);

	// lcs(X, Y)
	int n = X.length();
	int m = Y.length();

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

int minDeletions(string X) {

	// Delete such that result is a palindrome
	// Min deletions will result in longest palindrome
	// All u have to do is find the length of the longest palindromic subsequence
	// Once u get lps compare it with length of X for required operations.

	int lenOfLps = lps(X);

	return X.length() - lenOfLps;
}

int main() {

	string X = "agbcba";

	cout << minDeletions(X);
}