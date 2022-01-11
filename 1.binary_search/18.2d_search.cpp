// Given a row wise and column wise sorted array. Find the presence of a given key in it.
#include <iostream>
#include <vector>
using namespace std;

int findKey(vector<vector<int>> arr, int row, int column, int key) {

	int i = 0;
	int j = column - 1;

	while (i >= 0 and i < row and j >= 0 and j < column) {

		if (arr[i][j] == key)
			return arr[i][j];

		else if (arr[i][j] > key)
			j--;

		else
			i++;
	}

	return -1;
}

int main() {

	vector<vector<int>> arr = {
		{10, 20, 30, 40},
		{15, 25, 35, 45},
		{27, 29, 37, 48},
		{32, 43, 39, 50}
	};

	int row = sizeof(arr);
	int column = sizeof(arr[0]);

	int key = 29;
	// int key = 23;

	cout << findKey(arr, row, column, key);
}