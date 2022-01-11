#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// Approach 1: Sorting all the numbers
// Returns the kth largest integer in the array
int approach1(vector<int> arr, int k) {
	sort(arr.begin(), arr.end());
	return arr[arr.size() - k];
}

// Approach 2: Sorting only k numbers
int approach2(vector<int> arr, int k) {
	priority_queue<int, vector<int>, greater<int>> minh;

	for (int i = 0; i < arr.size(); i++) {
		minh.push(arr[i]);
		if (minh.size() > k)
			minh.pop();
	}

	return minh.top();
}

int main() {

	vector<int> arr = {7, 10, 4, 3, 20, 15};
	int k = 3;

	cout << approach1(arr, k) << "\n" << approach2(arr, k);
	return 0;
}
