// Given a string, find the length of the longest repeating subsequence such that the two subsequences don’t have same string character at the same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

#include <iostream>
using namespace std;

int modifiedLcs(string X, string Y) {

	// X and Y are same i.e X.
	int table[X.length() + 1][X.length() + 1];

	for (int i = 0; i <= X.length(); i++) {
		for (int j = 0; j <= X.length(); j++) {

			if (i == 0 || j == 0)
				table[i][j] = 0;

			else if (X[i - 1] == Y[j - 1] and i != j) {
				table[i][j] = 1 + table[i - 1][j - 1];
			}

			else
				table[i][j] = max(table[i - 1][j], table[i][j - 1]);
		}
	}

	return table[X.length()][Y.length()];
}

int lrs(string X) {

	// Repeating means it occurs again and again in same string
	// So, all I have to do is to find LCS(X, X) such that we ignore same characters and find the LCS

	return modifiedLcs(X, X);
}

int main() {

	string X = "aabeebcdd";

	cout << lrs(X);
}