#include <iostream>
#include <unordered_map>
using namespace std;

bool solve(string X, string Y) {

	if (X == Y)
		return true;
	if (X.length() <= 1) {
		// As X and Y are not same it means that
		// Either X and Y are one letter words or more than that
		// If more then we can break it further but if not
		// It means it is one letter and it is not same that means not scrambled
		return false;
	}

	int n = X.length() - 1;
	bool flag = false;

	// Partitions
	for (int i = 1; i <= n - 1; i++) {

		bool case1 = (solve(X.substr(0, i), Y.substr(n - i, i)) == true) and (solve(X.substr(i, n - i), Y.substr(0, n - i)) == true);

		bool case2 = (solve(X.substr(0, i), Y.substr(0, i)) == true ) and (solve(X.substr(i, n - i), Y.substr(i, n - i)) == true);

		if (case1 || case2) {
			flag = true; // string is scrambled
			break;
		}
	}

	return flag;
}


// For memoization: Make key = a + ' ' + b;

int main() {

	string X = "great";
	string Y = "rgeat";


	// Edge cases for question
	// if(X.length() != Y.length())
	// 	return false;
	// if(X == "" and Y == "")
	// 	return true;

	// // characters same or not
	// int countX[26] = {0};
	// int countY[26] = {0};

	// for(int i = 0; i < X.length(); i++) {
	// 	countX[X[i] - 'a']++;
	// 	countY[Y[i] - 'a']++;
	// }

	// for(int i = 0; i < 26; i++) {
	// 	if(countX[i] != countY[i])
	// 		return false;
	// }

	cout << solve(X, Y);
}