// Find the maximum element in all the subarrays of size k
#include <iostream>
#include <deque>
using namespace std;

void approach1(int *arr, int n, int windowSize) {

	deque<int> maxis;
	int i = 0, j = 0;

	while (j < n) {

		while (maxis.empty() == false and maxis.back() < arr[j]) {
			maxis.pop_back();
		}

		maxis.push_back(arr[j]);

		if (j - i + 1 < windowSize)
			j++;

		else if (j - i + 1 == windowSize) {

			cout << maxis.front() << " ";

			if (arr[i] == maxis.front())
				maxis.pop_front();

			i++, j++;
		}
	}
}

int main() {

	int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
	int n = sizeof(arr) / sizeof(int);

	int windowSize = 3;

	approach1(arr, n, windowSize);
}