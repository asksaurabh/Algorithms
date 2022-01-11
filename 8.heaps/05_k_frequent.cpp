// Find k frequent numbers
#include <bits/stdc++.h>
using namespace std;

// Prints k frequent numbers
void kfrequent(int *arr, int n, int k) {

	// Build a frequency map
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++)
		mp[arr[i]]++;

	// Build a min heap
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;

	for (auto pr : mp) {
		minh.push({pr.second, pr.first});
		if (minh.size() > k)
			minh.pop();
	}

	// Print the k frequent numbers
	while (minh.size() > 0) {
		cout << minh.top().second << " ";
		minh.pop();
	}
}

int main() {

	int arr[] = {1, 1, 1, 1, 3, 2, 2, 4};
	int n = sizeof(arr) / sizeof(int);
	int k = 2;

	kfrequent(arr, n, k);
	return 0;
}