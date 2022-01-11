// https://www.includehelp.com/algorithms/egg-dropping-problem-using-dynamic-programming.aspx

#include <iostream>
#include <climits>
using namespace std;

int solve(int e, int f) {

	if (f == 0 || f == 1)
		return f;
	if (e == 1)
		return f;

	int res = INT_MAX;
	for (int k = 1; k <= f; k++) {
		int tempAns = 1 + max(solve(e - 1, k - 1), solve(e, f - k));
		res = min(res, tempAns);
	}

	return res;
}

int main() {

	int f = 5;
	int e = 3;

	cout << solve(e, f);
}