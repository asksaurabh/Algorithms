// Find the minimum window substring in s in which all characters of t are present.
#include <bits/stdc++.h>
using namespace std;

int approach1(string s, string pat) {

	int minLength = INT_MAX;
	int i = 0, j = 0;
	unordered_map<char, int> mp;

	for (char ch : pat)
		mp[ch]++;
	int count = mp.size();

	while (j < s.length()) {

		if (mp.find(s[j]) != mp.end()) {
			mp[s[j]]--;
			if (mp[s[j]] == 0)
				count--;
			j++;
		}

		else if (count == 0) {
			// Min window reached
			minLength = min(minLength, j - i + 1);

			// remove extra and needless characters
			while (count == 0) {

				if (mp.find(s[i]) == mp.end())
					i++;
				else {
					mp[s[i]]++;
					if (mp[s[i]] > 0)
						count++;
					i++;
				}

				minLength = min(minLength, j - i + 1);
			}

			j++;
		}

		// When chaarcter is not in map.
		else
			j++;
	}

	return minLength;
}


int main() {

	string s = "geeksforgeeks";
	string pat = "ork";

	cout << approach1(s, pat);

	return 0;
}