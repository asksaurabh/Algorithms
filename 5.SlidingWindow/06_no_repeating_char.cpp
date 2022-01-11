// FInd the longest substring with no repeating character
#include <bits/stdc++.h>
using namespace std;

// Approach1: Idea is to find a substring containing all unique characters
int approach1(string s) {

	int maxLength = 0;
	int i = 0, j = 0;
	unordered_set<char> st;

	while (j < s.length()) {

		if (st.find(s[j]) != st.end()) {
			while (st.find(s[j]) != st.end()) {
				st.erase(s[i]);
				i++;
			}
		}

		st.insert(s[j]);
		maxLength = max(maxLength, j - i + 1);
		j++;
	}

	return maxLength;
}

// Approach2: Using map
// Idea is if curr winndow length is k then there should exactly be k unique characters in map
// Unique character is given by mp.size()
// So, comparison is done with window size (j - i + 1)

int approach2(string s) {

	int maxLength = 0;
	int i = 0, j = 0;
	unordered_map<char, int> mp;

	while (j < s.length()) {

		mp[s[j]]++;

		if (mp.size() == j - i + 1) {
			maxLength = max(maxLength, j - i + 1);
			j++;
		}

		else if (mp.size() < j - i + 1) {
			// Presence of extra character
			while (mp.size() < j - i + 1) {
				mp[s[i]]--;
				if (mp[s[i]] == 0)
					mp.erase(s[i]);
				i++;
			}

			if (mp.size() == j - i + 1)
				maxLength = max(maxLength, j - i + 1);

			j++;
		}
	}

	return maxLength;
}

int main() {

	string s = "pwwkew";

	cout << approach1(s) << " " << approach2(s);
	return 0;
}