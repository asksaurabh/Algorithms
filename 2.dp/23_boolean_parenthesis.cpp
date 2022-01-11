// Find the number of ways to apply parenthesis to the string str such that it evaluates to True.
#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;

int solve(string str, int i, int j, bool isExpression) {

	if (i > j)
		return 0;
	if (i == j) {
		if (isExpression == true)
			return str[i] == 'T';
		else
			return str[i] == 'F';
	}

	int res = 0;

	for (int k = i + 1; k <= j - 1; k += 2) {

		int ways_in_which_left_expr_is_true = solve(str, i, k - 1, true);
		int ways_in_which_left_expr_is_false = solve(str, i, k - 1, false);
		int ways_in_which_right_expr_is_true = solve(str, k + 1, j, true);
		int ways_in_which_right_expr_is_false = solve(str, k + 1, j, false);

		int lt = ways_in_which_left_expr_is_true;
		int lf = ways_in_which_left_expr_is_false;
		int rt = ways_in_which_right_expr_is_true;
		int rf = ways_in_which_right_expr_is_false;

		if (str[k] == '&') {
			if (isExpression == true)
				res += lt * rt;
			else
				res += lf * rf + lt * rf + lf * rt;
		}

		else if (str[k] == '|') {
			if (isExpression == true)
				res += lt * rt + lf * rt + lt * rf;
			else
				res += lf * rf;
		}

		else if (str[k] == '^') {
			if (isExpression == true)
				res += lt * rf + lf * rt;
			else
				res += lt * rt + lf * rf;
		}
	}

	return res;
}

unordered_map<string, int> mp;

int solveMemo(string str, int i, int j, bool isExpression) {

	if (i > j)
		return 0;
	if (i == j) {
		if (isExpression == true)
			return str[i] == 'T';
		else
			return str[i] == 'F';
	}

	string key = to_string(i) + ' ' + to_string(j) + ' ' + to_string(isExpression);
	if (mp.find(key) != mp.end())
		return mp[key];

	int res = 0;

	for (int k = i + 1; k <= j - 1; k += 2) {

		int lt = solveMemo(str, i, k - 1, true);
		int lf = solveMemo(str, i, k - 1, false);
		int rt = solveMemo(str, k + 1, j, true);
		int rf = solveMemo(str, k + 1, j, false);

		if (str[k] == '&') {
			if (isExpression == true)
				res += lt * rt;
			else
				res += lf * rf + lt * rf + lf * rt;
		}

		else if (str[k] == '|') {
			if (isExpression == true)
				res += lt * rt + lf * rt + lt * rf;
			else
				res += lf * rf;
		}

		else if (str[k] == '^') {
			if (isExpression == true)
				res += lt * rf + lf * rt;
			else
				res += lt * rt + lf * rf;
		}
	}

	return mp[key] = res;
}

int main() {

	string str = "T|F&T^F";
	// string str = "T^F&T";

	int i = 0;
	int j = str.length() - 1;
	bool isExpression = true;

	cout << solve(str, i, j, isExpression) << " " << solveMemo(str, i, j, isExpression);
}