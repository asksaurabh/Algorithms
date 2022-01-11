#include <bits/stdc++.h>
using namespace std;

bool floyd_warshall(vector<vector<int>> &graph, int V, vector<vector<int>> &distance) {

	// Initialize a distance matrix
	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			distance[i][j] = graph[i][j];

	// Phases: In kth phase, we innclude (1...k) as intermediate vertices.
	for (int k = 0; k < V; k++) {

		// In each phase iterate over entire 2D graph
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				// Find the shortest path between i to j with k as intermediate
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
			}
		}

	}

	// To detect the -ve cycle, if distance o any vertex from itself becomes -ve
	bool isNegativeCyclePresent = false;
	for (int i = 0; i < V; i++)
		if (distance[i][i] < 0)
			isNegativeCyclePresent = true;

	return isNegativeCyclePresent;
}

void printAdjMatrix(vector<vector<int>> &graph, int V) {
	// Print Adjacency Matrix (GRAPH)
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}

void solve() {

	int V, E;
	cin >> V >> E;

	vector<vector<int>> graph(V, vector<int> (V, 1000));

	// Initialization: graph[src][src] = 0, If no path then 1000, If path then wt.
	for (int i = 0; i < E; i++) {
		int src, dest, wt;
		cin >> src >> dest >> wt;

		graph[src][dest] = wt;
		graph[src][src] = 0;
	}

	printAdjMatrix(graph, V);
	vector<vector<int>> sp(V, vector<int> (V, INT_MAX));

	bool isNegativeCyclePresent = floyd_warshall(graph, V, sp);

	if (isNegativeCyclePresent == false) {
		// Print shortest path between all pairs of nodes
		cout << "-------------------\n";
		printAdjMatrix(sp, V);
	}

}

int main() {
	solve();
	return 0;
}

// 4 5
// 1 0 4
// 0 2 -2
// 2 3 2
// 3 1 -1
// 1 2 3