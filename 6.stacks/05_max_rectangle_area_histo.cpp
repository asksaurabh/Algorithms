// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
#include <bits/stdc++.h>
using namespace std;

void nearestSmallerToLeft(int *arr, int n, vector<int> &nsl) {

	stack<pair<int, int>> s;

	for (int i = 0; i < n; i++) {

		while (s.empty() == false and s.top().first >= arr[i])
			s.pop();

		if (s.empty())
			nsl.push_back(-1);
		else
			nsl.push_back(s.top().second);

		s.push({arr[i], i});
	}
}

void nearestSmallerToRight(int *arr, int n, vector<int> &nsr) {

	stack<pair<int, int>> s;

	for (int i = n - 1; i >= 0; i--) {

		while (s.empty() == false and s.top().first >= arr[i])
			s.pop();

		if (s.empty())
			nsr.push_back(n);
		else
			nsr.push_back(s.top().second);

		s.push({arr[i], i});
	}

	reverse(nsr.begin(), nsr.end());

}

int approach1(int *arr, int n) {

	vector<int> nsl, nsr;
	nearestSmallerToLeft(arr, n, nsl);
	nearestSmallerToRight(arr, n, nsr);

	int maxRectangleArea = -1;

	for (int i = 0; i < n; i++) {

		maxRectangleArea = max(maxRectangleArea, (nsr[i] - nsl[i] - 1) * arr[i]);
	}

	return maxRectangleArea;
}

int main() {

	int arr[] = {6, 2, 5, 4, 5, 1, 6};
	int n = sizeof(arr) / sizeof(int);

	cout << approach1(arr, n);
	return 0;
}