// Given a key, find the next alphabetical letter in the the given sorted character array
#include <iostream>
#include <vector>
using namespace std;

int findNextLetterInArray(vector<char> arr, char key) {

	int n = arr.size();
	int start = 0;
	int end = n - 1;
	int res = -1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == key) {
			// Keep on searching on right as we have to give the next greater
			start = mid + 1;
		}

		else if (arr[mid] > key) {
			// possible candidate
			res = mid;
			end = mid - 1;
		}

		else
			start = mid + 1;
	}

	return res;
}

int main() {

	vector<char> arr = {'b', 'd', 'i', 'j', 'q', 't'};

	// char key = 'q';
	char key = 't';
	// char key = 'a';
	// char key = 'e';
	// char key = 'j';
	// char key = 'v';

	cout << findNextLetterInArray(arr, key);
}