// Find k closest numbers to a number X
#include <bits/stdc++.h>
using namespace std;

// Prints k closest numbers to number X
void kClosest(int *arr, int n, int k, int X) {

	priority_queue < pair<int, int>, vector<pair<int, int>> >maxh;

	for (int i = 0; i < n; i++) {

		maxh.push({abs(arr[i] - X), arr[i]});
		if (maxh.size() > k)
			maxh.pop();

	}

	while (maxh.size() > 0) {
		cout << maxh.top().second << " ";
		maxh.pop();
	}
}

int main() {

	int arr[] = {6, 5, 8, 7, 9};
	int n = sizeof(arr) / sizeof(int);
	int k = 3;
	int X = 7;

	kClosest(arr, n, k, X);
	return 0;
}