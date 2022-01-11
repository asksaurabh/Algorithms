#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// Approach 1: Sorting all the numbers
// Returns the kth smallest integer in the array
int approach1(vector<int> arr, int k) {
	sort(arr.begin(), arr.end());
	return arr[k - 1];
}

// Approach2: Sorting only k numbers
int approach2(vector<int> arr, int k) {
	priority_queue<int> maxh;

	for (int i = 0; i < arr.size(); i++) {
		maxh.push(arr[i]);
		if (maxh.size() > k) {
			maxh.pop();
		}
	}

	return maxh.top();
}


int main() {

	vector<int> arr = {7, 10, 4, 3, 20, 15};
	int k = 3;

	cout << approach1(arr, k) << "\n" << approach2(arr, k);
	return 0;
}