
#include <bits/stdc++.h>
using namespace std;

class Compare {
public:
	int operator()(pair<int, int>& pr1, pair<int, int>& pr2) {
		// .first -> freq, .second -> val
		if (pr1.first != pr2.first)
			return pr1.first < pr2.first;

		return pr1.second < pr2.second;
	}
};

// Prints the arr in decreasing order of frequency. If same, then print smaller number first
void frequencySort(int *arr, int n) {

	// Create a map of frequency
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[arr[i]]++;
	}

	// Build a max heap of frequencies but with few specialities
	priority_queue <pair<int, int>, vector<pair<int, int>>, Compare> maxh;

	// Store in max heap {freq, val}
	for (auto pr : mp) {
		maxh.push({pr.second, pr.first});
	}

	// Print the correct order
	while (maxh.size() > 0) {
		int freq = maxh.top().first;
		int val = maxh.top().second;

		while (freq--)
			cout << val << " ";

		maxh.pop();
	}
}

int main() {

	int arr[] = {1, 1, 1, 1, 3, 2, 2, 4, 4};
	int n = sizeof(arr) / sizeof(int);

	frequencySort(arr, n);
	return 0;
}