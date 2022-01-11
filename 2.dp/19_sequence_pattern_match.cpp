// Given two strings X(smaller than Y) and Y, Find if X is a subsequence of Y.
#include <iostream>
using namespace std;

// BEST: Two Pointer
bool isSubsequence(string X, string Y) {

	int x_i = 0;

	for (int y_i = 0; y_i < Y.length() and x_i < X.length(); y_i++) {
		if (Y[y_i] == X[x_i])
			x_i++;
	}

	return x_i == X.length();
}

// recursive Approach
bool isSubs(string X, string Y, int n, int m) {

	if (n == 0)
		return true;
	if (m == 0 and n != 0)
		return false;


	if (X[n - 1] == Y[m - 1])
		return isSubs(X, Y, n - 1, m - 1);
	else
		return isSubs(X, Y, n, m - 1);
}

// DP Approach
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

bool subs(string X, string Y) {

	int n = X.length();
	int m = Y.length();

	// if X is subsequence of Y, then X should lie completely in Y. LCS(X, Y) == X
	int lcsLength = lcs(X, Y, n, m);

	return lcsLength == X.length();
}

int main() {

	string X = "axy";
	string Y = "acxdfy";

	cout << isSubsequence(X, Y) << " " << subs(X, Y) << " " << isSubs(X, Y, X.length(), Y.length());
}