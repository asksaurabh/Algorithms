#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {

	double ratio1 = (double) a.second / a.first;
	double ratio2 = (double) b.second / b.first;

	return ratio1 > ratio2;
}

double fractionalKnapsack(vector<pair<int, int>> wtVal, int Wmax) {

	// Sort in decreasing order of val/wt ratio
	sort(wtVal.begin(), wtVal.end(), compare);

	double valueCollected = 0.0;

	for (int i = 0; i < wtVal.size(); i++) {

		if (wtVal[i].first <= Wmax) {
			// Choose whole
			Wmax -= wtVal[i].first;
			valueCollected += wtVal[i].second;
		}

		else {
			valueCollected += wtVal[i].second * ((double)Wmax / wtVal[i].first);
			break;
		}
	}

	return valueCollected;
}

int main() {

	vector<pair<int, int>> wtVal = {{50, 600}, {20, 500}, {30, 400}};
	int Wmax = 70;

	cout << fractionalKnapsack(wtVal, Wmax);
	return 0;
}