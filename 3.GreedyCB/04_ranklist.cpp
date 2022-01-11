// https://www.spoj.com/problems/BAISED/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minBadnessSTL(vector<int> ranklist) {

	sort(ranklist.begin(), ranklist.end());

	int badness = 0;
	int atRank = 1;

	for (int i = 0; i < ranklist.size(); i++) {
		badness += abs(atRank - ranklist[i]);
		atRank++;
	}

	return badness;
}

int minBadnessUsingCountingSort(vector<int> &ranklist) {

	// Rank is between 1 and N(ranklist.size)
	int N = ranklist.size();

	// Storing the count of every rank preferred by teams
	int count[N + 1] = {0};
	for (int i = 0; i < ranklist.size(); i++) {
		count[ranklist[i]]++;
	}

	// Iterate over the count[] to allot rank
	int allotRank = 1;
	int badness = 0;

	// Allot rank between 1 to N
	for (int i = 1; i <= N; i++) {
		while (count[i] != 0) {
			badness += abs(allotRank - i);
			allotRank++;
			count[i]--;
		}
	}

	return badness;
}

int main() {

	int teams;
	cin >> teams;

	vector<int> ranklist;
	for (int i = 0; i < teams; i++) {
		string teamName;
		int preferredRank;

		cin >> teamName >> preferredRank;
		ranklist.push_back(preferredRank);
	}

	cout << minBadnessSTL(ranklist) << endl;
	cout << minBadnessUsingCountingSort(ranklist);
}

// Input:
// 7
// noobz 1
// llamas 2
// Winn3rz 2
// 5thwheel 1
// NotoricCoders 5
// StrangeCase 7
// WhoKnows 7

