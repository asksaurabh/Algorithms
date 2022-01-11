#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

int maxProfit(vector<pair<int, int>> jobs) {

    sort(jobs.begin(), jobs.end(), compare);

    int curr_deadline = 0;
    int profit = 0;

    for (int i = 0; i < jobs.size(); i++) {

        if (jobs[i].first > curr_deadline) {
            // Pick this job
            curr_deadline++;
            profit += jobs[i].second;
        }

    }

    return profit;
}

int main() {

    // vector<pair<int, int>> jobs = {{4,70}, {1,80}, {1,30}, {1, 100}};
    vector<pair<int, int>> jobs = {{2, 50}, {2, 60}, {3, 20}, {3, 30}};
    cout << maxProfit(jobs);
}
