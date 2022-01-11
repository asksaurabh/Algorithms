// GIven two strings, find the length of longest common subsequence
#include <iostream>
using namespace std;

int lcs(string X, string Y, int n, int m) {

	if (n == 0 || m == 0)
		return 0;

	if (X[n - 1] == Y[m - 1])
		return 1 + lcs(X, Y, n - 1, m - 1);
	else
		return max(lcs(X, Y, n - 1, m), lcs(X, Y, n, m - 1));
}

int LCS(string X, string Y, int n, int m) {

	int table[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
		table[i][0] = 0;
	for (int i = 0; i <= m; i++)
		table[0][i] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (X[i - 1] == Y[j - 1])
				table[i][j] = 1 + table[i - 1][j - 1];
			else
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		}
	}

	return table[n][m];
}

int main() {

	string X = "abcde";
	string Y = "abfder";

	cout << lcs(X, Y, X.length(), Y.length()) << " " ;
	cout << LCS(X, Y, X.length(), Y.length());
}