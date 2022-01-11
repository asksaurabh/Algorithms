// Find k closest points to origin
#include <bits/stdc++.h>
using namespace std;

// Distance of point (x, y) with origin is sqrt(x^2 + y^2). So, minimize this.

void kclosestPointsToOrigin(pair<int, int> arr[], int n, int k) {

	// Build a max heap so that u can remove bigger distances
	// Store { distance, {x,y} }
	priority_queue<pair<int, pair<int, int>> > maxh;

	for (int i = 0; i < n; i++) {
		int dist = pow(arr[i].first, 2) + pow(arr[i].second, 2);

		// arr[i] is a pair
		maxh.push({dist, arr[i]});

		if (maxh.size() > k)
			maxh.pop();
	}

	// Print the points
	while (maxh.size() > 0) {
		cout << maxh.top().second.first << ", " << maxh.top().second.second << "\n";
		maxh.pop();
	}
}

int main() {

	pair<int, int> arr[] = {{1, 3}, { -2, 2}, {5, 8}, {0, 1}};
	int n = sizeof(arr) / (2 * sizeof(int));
	int k = 2;

	kclosestPointsToOrigin(arr, n, k);
	return 0;
}