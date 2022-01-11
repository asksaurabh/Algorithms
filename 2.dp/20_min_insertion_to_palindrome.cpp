// Given a string, find the minimum number of insertions required to make it a palindrome
#include <iostream>
using namespace std;

int lps(string X) {

	// LPS (X) == LCS(X, rev(X))

	string R = "";
	for (int i = X.length() - 1; i >= 0; i--)
		R.push_back(X[i]);

	int n = X.length();

	int table[n + 1][n + 1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {

			if (i == 0 || j == 0)
				table[i][j] = 0;

			else if (X[i - 1] == R[j - 1])
				table[i][j] = 1 + table[i - 1][j - 1];

			else
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		}
	}

	return table[n][n];
}

int minInsertions(string X) {

	// Idea is to see the min deletions required to make a palindrome
	// Min deletions will give a LPS
	// So, whatever u delete u donot need to make a LPS
	// So, the items u delete, if u insert such that to make a pair for palindrome
	// minInsertions == minDeletions == X.length() - LPS

	int lpsLength = lps(X);
	return X.length() - lpsLength;
}

int main() {

	string X = "aebcbda";

	cout << minInsertions(X);
}