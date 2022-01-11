// Given a string X, find the length of the longest palindromic subsequence

#include <iostream>
using namespace std;

int lcs(string X, string Y) {

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

int lps(string X) {

	string Y = "";
	for (int i = X.length() - 1; i >= 0; i--)
		Y.push_back(X[i]);

	return lcs(X, Y);
}

int main() {

	string X = "abfzcba";
	cout << lps(X);
}