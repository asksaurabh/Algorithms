// Given is a rack of toys of various types
// Maximize the no of toys chosen by kid such that:
// 1. He has to pick toys in same line. Can't skip btw toys
// 2. He can pick only 2 types of toys.
// Task is to maximize the no of 2 types of toys chosen by kid

// Parent Ques: Longest substring with atmost k unique characters

#include <bits/stdc++.h>
using namespace std;

int approach1(string s) {

	int maxToys = 0;
	int i = 0, j = 0;
	unordered_map<char, int> mp;

	while (j < s.length()) {

		mp[s[j]]++;

		if (mp.size() <= 2) {

			int curr_toys = 0;
			for (auto toy : mp) {
				curr_toys += toy.second;
			}

			maxToys = max(maxToys, curr_toys);
			j++;
		}

		else if (mp.size() > 2) {

			while (mp.size() > 2) {
				mp[s[i]]--;
				if (mp[s[i]] == 0)
					mp.erase(s[i]);
				i++;
			}

			if (mp.size() == 2) {
				int curr_toys = 0;
				for (auto toy : mp) {
					curr_toys += toy.second;
				}

				maxToys = max(maxToys, curr_toys);
			}

			j++;
		}
	}

	return maxToys;
}


int main() {

	// Denoting types of toys
	string s = "abaccab";

	cout << approach1(s);
	return 0;
}