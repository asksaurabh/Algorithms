// https://www.spoj.com/problems/BALIFE/

#include <iostream>
using namespace std;

int minRoundsToBalance(int arr[], int n) {

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	// If sum can't be equally divided between n jobs, return -1
	if (sum % n != 0)
		return -1;

	int avgLoad = sum / n;

	// Find out which job will export and which will import
	// If arr[i] > 0 : It will export those many jobs in later rounds
	// If arr[i] < 0 : It will import those many jobs in later rounds

	for (int i = 0; i < n; i++)
		arr[i] = arr[i] - avgLoad;

	// Run a pre computation technique to find out the balancing
	for (int i = 1; i < n; i++)
		arr[i] = arr[i] + arr[i - 1];

	// Result will the absolute value of the number of rounds required in each job
	int res = -1;
	for (int i = 0; i < n; i++) {
		res = max(abs(arr[i]), res);
	}

	return res;
}

int main() {

	// int jobs[] = {6, 0, 0, 10};
	int jobs[] = {16 , 17, 15, 0, 20, 1, 1, 2};
	int n = sizeof(jobs) / sizeof(int);

	cout << minRoundsToBalance(jobs, n);
	return 0;
}

// APPROACH:
// base case : if number of jobs of all processors is not divisible by n print -1.

// else

// find average.

// lets say a[i] is the list of jobs assigned to i th processor.

// from each job a[i] do a[i] - avg. if a[i] is +ve it means it has to export this many jobs to neighbors and -ve means it has to import this may jobs from neighbors .
// 2. for all i do a[i] =a[i] + a[i - 1] i.e. find sum till i.

// 3. find max absolute value from a[i] and print it.

// explanation:

// lets say a[i] after performing step 1 is: [ 2 ,-5, 7, -4]

// after performing step 2 array will become [2, -3, 4, 0]

// what it means is that first processor has 2 extra jobs and it can export it in 2 round.

// 2nd processor has 5 jobs to import. It can take 2 from 1st processor, it has still 3 more to import. and it can be done in 3 rounds.

// 3rd processor has 7 jobs to export. It can export 3 to previous processor in 3 round and it has remaining 4 jobs, which can be exported in 4 rounds to the next processor.

// 4th processor has to import 4 jobs and it can import it from previous processor in 4 rounds. Hence max rounds is the max absolute value from a[i].