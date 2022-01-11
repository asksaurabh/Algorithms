#include <bits/stdc++.h>
using namespace std;

void approach1(int *arr, int n, int windowSize) {

	for (int i = 0; i <= n - windowSize; i++) {
		int res = 0;
		for (int j = 0; j < windowSize; j++) {
			if (arr[i + j] < 0) {
				res = arr[i + j];
				break;
			}
		}

		cout << res << " ";
	}
}

void approach2(int *arr, int n, int windowSize) {

	int i = 0, j = 0;
	list<int> l;

	while (j < n) {
		if (arr[j] < 0)
			l.push_back(arr[j]);

		if (j - i + 1 < windowSize)
			j++;

		else if (j - i + 1 == windowSize) {

			if (l.empty() == false)
				cout << l.front() << " ";
			else
				cout << "0 ";

			if (arr[i] < 0)
				l.pop_front();

			i++, j++;
		}
	}
}

int main() {

	int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
	int n = sizeof(arr) / sizeof(int);

	int windowSize = 3;

	approach1(arr, n, windowSize);
	cout << "\n";
	approach2(arr, n, windowSize);

	return 0;
}