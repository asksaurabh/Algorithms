// Given n white dots ans n black dots positions. Task is to connect the white dots with black dots such that length of rope required would be minimum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfRopeRequired(vector<int> &whiteDots, vector<int> &blackDots) {

	sort(whiteDots.begin(), whiteDots.end());
	sort(blackDots.begin(), blackDots.end());

	int minLength = 0;

	for (int i = 0; i < whiteDots.size(); i++) {
		minLength += abs(whiteDots[i] - blackDots[i]);
	}

	return minLength;
}

int main() {

	vector<int> whiteDots = {0, 2, 3};
	vector<int> blackDots = {1, 4, 5};

	cout << lengthOfRopeRequired(whiteDots, blackDots);
}