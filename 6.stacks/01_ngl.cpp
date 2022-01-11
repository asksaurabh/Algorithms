// Find the nearest greater to left/ Find previous greater element.
#include <bits/stdc++.h>
using namespace std;

void approach1(int *arr, int n) {

	for (int i = 0; i < n; i++) {
		int nearestGreaterToLeft = -1;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[i]) {
				nearestGreaterToLeft = arr[j];
				break;
			}
		}
		cout << nearestGreaterToLeft << " ";
	}

	cout << endl;
}

void approach2(int *arr, int n) {
	vector<int> result(n);
	stack<int> s;

	for (int i = 0; i < n; i++) {

		while (s.empty() == false and s.top() <= arr[i])
			s.pop();

		if (s.empty())
			result[i] = -1;
		else
			result[i] = s.top();

		s.push(arr[i]);
	}

	for (int val : result)
		cout << val << " ";
}

int main() {

	int arr[] = {1, 3, 0, 0, 8, 5, 2, 3, 8};
	// int arr[] = {1, 1, 1, 1, 1};
	int n = sizeof(arr) / sizeof(int);

	approach1(arr, n);
	approach2(arr, n);
	return 0;
}