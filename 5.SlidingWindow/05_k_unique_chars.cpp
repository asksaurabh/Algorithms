// Find the longest substring with k unique characters
#include <bits/stdc++.h>
using namespace std;

int approach1(string s, int uniqueCharacters) {

	int maxLength = -1;

	int i = 0, j = 0;
	unordered_map<char, int> mp;

	while (j < s.length()) {

		mp[s[j]]++;

		if (mp.size() < uniqueCharacters)
			j++;

		else if (mp.size() == uniqueCharacters) {
			maxLength = max(maxLength, j - i + 1);
			j++;
		}

		else if (mp.size() > uniqueCharacters) {

			while (mp.size() > uniqueCharacters) {
				mp[s[i]]--;
				if (mp[s[i]] == 0)
					mp.erase(s[i]);
				i++;
			}

			if (mp.size() == uniqueCharacters)
				maxLength = max(maxLength, j - i + 1);

			j++;
		}
	}

	return maxLength;
}

int main() {

	string s = "aabacbebebe";
	int uniqueCharacters = 3;

	cout << approach1(s, uniqueCharacters);
	return 0;
}