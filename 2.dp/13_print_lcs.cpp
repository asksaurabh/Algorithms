#include <iostream>
#include <algorithm>
using namespace std;

void printLcs(string X, string Y, int n, int m) {

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

	string result = "";
	int i = n, j = m;

	while (i > 0 and j > 0) {
		if (X[i - 1] == Y[j - 1]) {
			result.push_back(X[i - 1]);
			i--;
			j--;
		}

		else {
			if (table[i - 1][j] > table[i][j - 1])
				i--;
			else
				j--;
		}
	}

	reverse(result.begin(), result.end());
	cout << result;
}

int main() {

	string X = "abcde";
	string Y = "abgder";

	printLcs(X, Y, X.length(), Y.length());
}