// https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a1, pair<int, int> a2) {
	return a1.second < a2.second;
}


int activitySelection(vector<pair<int, int>> &v) {

	// Selected the first activity automatically as it has least time
	int res = 1;
	int curr_finish_time = v[0].second;

	for (int i = 1; i < v.size(); i++) {
		if (v[i].first >= curr_finish_time) {
			// Do that activity
			res++;
			curr_finish_time = v[i].second;
		}
	}

	return res;
}
int main() {

	vector<pair<int, int>> activity = {{7, 9}, {0, 10}, {4, 5}, {8, 9}, {4, 10}, {5, 7}};

	// Sort the vector in the order of increasing end time.
	sort(activity.begin(), activity.end(), compare);

	// Now activity selection algorithm
	cout << activitySelection(activity);

	return 0;
}