// Given two strings, Find the length of the shortest common supersequence
#include <iostream>
using namespace std;

int lcs(string X, string Y, int n, int m) {

	int table[n + 1][m + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {

			if (i == 0 || j == 0) {
				table[i][j] = 0;
			}

			else if (X[i - 1] == Y[j - 1]) {
				table[i][j] = 1 + table[i - 1][j - 1];
			}

			else
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		}
	}

	return table[n][m];
}

int scs(string X, string Y, int n, int m) {

	// Idea is X + Y - LCS
	// Terms which are common should be written only once

	int lcsLength = lcs(X, Y, n, m);
	return n + m - lcsLength;
}

int main() {

	string X = "geek";
	string Y = "eke";

	// geeke
	cout << scs(X, Y, X.length(), Y.length());
}