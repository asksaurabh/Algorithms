// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
#include <iostream>
#include <climits>
using namespace std;

bool isPalindrome(string str, int i, int j) {

	while (i < j) {
		if (str[i] != str[j])
			return false;
		i++;
		j--;
	}

	return true;
}

int solve(string str, int i, int j) {

	if (i >= j || isPalindrome(str, i, j))
		return 0;

	int res = INT_MAX;

	for (int k = i; k <= j - 1; k++) {

		int tempAns = solve(str, i, k) + solve(str, k + 1, j) + 1;
		res = min(res, tempAns);

	}

	return res;
}

int main() {

	string str = "nitinx";

	int i = 0;
	int j = str.length() - 1;
	cout << solve(str, i, j);
}