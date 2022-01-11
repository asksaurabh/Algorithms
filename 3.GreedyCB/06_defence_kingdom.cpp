// https://www.spoj.com/problems/DEFKIN/
#include<iostream>
#include <algorithm>
using namespace std;

int main() {

	int width, height, towers;
	cin >> width >> height >> towers;

	int x[100001], y[100001];

	for (int i = 0; i < towers; i++) {
		cin >> x[i] >> y[i];
	}

	sort(x, x + towers);
	sort(y, y + towers);

	// Calculating largest undefended x and y coordintes

	// Before the first tower
	int dx = x[0] - 1;
	int dy = y[0] - 1;

	for (int i = 1; i < towers; i++) {

		int curr_undefended_x = x[i] - x[i - 1] - 1;
		int curr_undefended_y = y[i] - y[i - 1] - 1;

		dx = max(dx , curr_undefended_x);
		dy = max(dy , curr_undefended_y);
	}

	// After the last tower
	dx = max(dx, width - x[towers - 1]);
	dy = max(dy, height - y[towers - 1]);

	// Largest undefended rectangle
	cout << dx*dy;
}

// INPUT:
// 15 8 3
// 3 8
// 11 2
// 8 6