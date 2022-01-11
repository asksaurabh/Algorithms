// https://www.geeksforgeeks.org/the-stock-span-problem/
#include <bits/stdc++.h>
using namespace std;

void approach1(int *arr, int n) {

	for (int i = 0; i < n; i++) {
		int curr_count = 1;

		for (int j = i - 1; j >= 0; j--) {

			if (arr[j] > arr[i])
				break;
			curr_count++;
		}

		cout << curr_count << " ";
	}

	cout << endl;
}

void approach2(int *arr, int n) {
	// Idea is to stop searching in left when u find nearest greater to left
	vector<int> result;
	stack<pair<int, int>> s;

	for (int i = 0; i < n; i++) {

		while (s.empty() == false and s.top().first <= arr[i])
			s.pop();

		if (s.empty())
			result.push_back(1);
		else
			result.push_back(i - s.top().second);

		s.push({arr[i], i});
	}

	for (int val : result)
		cout << val << " ";
}

int main() {

	int arr[]  = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(arr) / sizeof(int);

	approach1(arr, n);
	approach2(arr, n);
	return 0;
}