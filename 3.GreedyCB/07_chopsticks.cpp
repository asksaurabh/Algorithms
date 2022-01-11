// https://www.codechef.com/problems/TACHSTCK
#include <iostream>
#include <algorithm>
using namespace std;

int maxUsablePairs(int arr[], int N, int D) {

	sort(arr, arr + N);
	int count = 0;

	for (int i = 0; i <= N - 2; ) {
		if (arr[i + 1] - arr[i] <= D) {
			count++;
			i = i + 2;
		}

		else
			i++;
	}

	return count;
}

int main() {

	int N, D;
	cin >> N >> D;

	int arr[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cout << maxUsablePairs(arr, N, D);
}

// INPUT:
// 5 2
// 1 3 3 9 4