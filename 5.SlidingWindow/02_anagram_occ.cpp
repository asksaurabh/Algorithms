// Count occurences of anagrams of a given pattern in a given string s.
// Anagram -> same letters, same quantity
#include <bits/stdc++.h>
using namespace std;

int approach1(string s, string pat) {

	int windowSize = pat.length();
	int i = 0, j = 0, count = 0;

	int sCount[26] = {0}, patCount[26] = {0};

	for (char ch : pat) {
		patCount[ch - 'a']++;
	}

	while (j < s.length()) {

		sCount[s[j] - 'a']++;
		if (j - i + 1 < windowSize)
			j++;

		else if (j - i + 1 == windowSize) {

			bool flag = true;
			for (int k = 0; k < 26; k++) {
				if (sCount[k] != patCount[k])
					flag = false;
			}

			if (flag)
				count++;

			sCount[s[i] - 'a']--;
			i++, j++;
		}
	}

	return count;
}

// Approach2: Optimize for the extra arrays and efficient search
int approach2(string s, string pat) {

	int windowSize = pat.length();
	int i = 0, j = 0;

	unordered_map<char, int> mp;
	int count = 0;     // Showing distinct characters in map with count > 0

	for (char ch : pat)
		mp[ch]++;
	count = mp.size();

	int result = 0;

	while (j < s.length()) {

		if (mp.find(s[j]) != mp.end()) {
			mp[s[j]]--;
			if (mp[s[j]] == 0)
				count--;
		}

		if (j - i + 1 < windowSize)
			j++;

		else if (j - i + 1 == windowSize) {

			if (count == 0)
				result++;

			if (mp.find(s[i]) != mp.end()) {
				mp[s[i]]++;
				if (mp[s[i]] == 1)
					count++;
			}

			i++, j++;
		}

	}

	return result;
}

int main() {

	string s = "aabaabaa";
	string pat = "aaba";

	cout << approach1(s, pat) << " " << approach2(s, pat);
	return 0;
}