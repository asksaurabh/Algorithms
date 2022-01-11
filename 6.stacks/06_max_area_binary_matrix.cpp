// https://www.geeksforgeeks.org/maximum-size-rectangle-binary-sub-matrix-1s/
#include <bits/stdc++.h>
# define C 4
# define R 4
using namespace std;

void nearestSmallerToLeft(vector<int> &arr, int n, vector<int> &nsl) {

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

void nearestSmallerToRight(vector<int> &arr, int n, vector<int> &nsr) {

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

int MAH(vector<int> &arr, int n) {

	vector<int> nsl, nsr;
	nearestSmallerToLeft(arr, n, nsl);
	nearestSmallerToRight(arr, n, nsr);

	int maxRectangleArea = -1;

	for (int i = 0; i < n; i++) {

		maxRectangleArea = max(maxRectangleArea, (nsr[i] - nsl[i] - 1) * arr[i]);
	}

	return maxRectangleArea;
}

int maxAreaInBinaryMatrixWithAllOnes(int A[][C]) {

	vector<int> currentHistogram(C, 0);
	int maxArea = 0;

	for (int i = 0; i < R; i++) {

		for (int j = 0; j < C; j++) {
			currentHistogram[j] = A[i][j] == 0 ? 0 : currentHistogram[j] + A[i][j];
		}

		maxArea = max(maxArea, MAH(currentHistogram, C));
	}

	return maxArea;
}

int main() {

	int A[][C] = {
		{ 0, 1, 1, 0 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 0, 0 },
	};

	cout << maxAreaInBinaryMatrixWithAllOnes(A);

	return 0;
}