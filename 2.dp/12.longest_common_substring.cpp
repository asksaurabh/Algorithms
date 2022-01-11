// Given two strings, find the length of the longest common substring
#include <iostream>
using namespace std;

int lSub(string X, string Y, int n, int m, int result) {

	if (n == 0 || m == 0)
		return result;

	if (X[n - 1] == Y[m - 1]) {
		result = lSub(X, Y, n - 1, m - 1, result + 1);
	}

	else
		result = max(result, max(lSub(X, Y, n - 1, m, 0), lSub(X, Y, n, m - 1, 0)));

	return result;
}

// longestCommSubstring() -> Gives the length of the longest common substring of string X ending with index n-1 and string Y ending with index m-1.

int longestCommSubstring(string X, string Y, int n, int m) {

	int table[n + 1][m + 1];
	int result = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {

			if (i == 0 || j == 0)
				table[i][j] = 0;

			else if (X[i - 1] == Y[j - 1]) {
				table[i][j] = 1 + table[i - 1][j - 1];
				result = max(result, table[i][j]);
			}

			else
				table[i][j] = 0;
		}
	}

	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= m; j++) {
	// 		cout << table[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	return result;
}


int main() {

	string X = "abcde";
	string Y = "abfder";

	cout << lSub(X, Y, X.length(), Y.length(), 0) << endl;
	cout << longestCommSubstring(X, Y, X.length(), Y.length());
}