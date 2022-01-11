// https://www.geeksforgeeks.org/detect-negative-cycle-graph-bellman-ford/
// BELLMAN FORD FOR DIRECTED GRAPHS
// For undirected treat them as bidirected graph for -ve cycle detection
// it is also possible that negative cycle is present in disconnected graph. Check for that also.

// So, this code detects -ve cycle in connected + disconnected components as well as prints the distance from source to other vertices.

#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	vector<vector<int>> edgeList;
public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int src, int dest, int wt) {
		edgeList.push_back({src, dest, wt});
	}


	// Prints the shorest path between source and all other nodes
	bool bellman_ford(int source, vector<int> &distance) {

		for (int i = 0; i < V; i++)
			distance[i] = INT_MAX;
		distance[source] = 0;

		// Relax all the edges V - 1 times
		for (int relax = 1; relax <= V - 1; relax++) {

			// Iterate over all the edges and relax them
			for (auto edge : edgeList) {
				int src = edge[0], dest = edge[1], wt = edge[2];

				if (distance[src] != INT_MAX and distance[src] + wt < distance[dest])
					distance[dest] = distance[src] + wt;
			}
		}

		// Check negative cycle
		bool isNegativeCyclePresent = false;

		// Try to relax for one more time and see if distance array changes
		for (auto edge : edgeList) {
			int src = edge[0], dest = edge[1], wt = edge[2];

			if (distance[src] != INT_MAX and distance[src] + wt < distance[dest]) {
				isNegativeCyclePresent = true;
				break;
			}
		}

		// If negative cycle not present print distances
		if (isNegativeCyclePresent == false) {
			for (int i = 0; i < V; i++) {
				cout << "Src: " << source << " Dest: " << i << " Dist: " << distance[i] << "\n";
			}
		}

		return isNegativeCyclePresent;
	}

	// To detect if negative cycle is present in a disconnected component
	bool bellman_ford_for_all_components() {
		vector<bool> visited(V, false);
		vector<int> distance(V);

		// Call bellman_ford for all vertices which are not visited
		for (int i = 0; i < V; i++) {
			if (visited[i] == false) {
				if (bellman_ford(i, distance) == true)
					return true;

				// Mark the visited vertices in above call true
				for (int i = 0; i < V; i++)
					if (distance[i] != INT_MAX)
						visited[i] = true;
			}
		}

		// If no cycle detected.
		return false;
	}

};

void solve() {
	int V, E, source;
	cin >> V >> E >> source;

	Graph g(V);
	for (int i = 0; i < E; i++) {
		int src, dest, wt;
		cin >> src >> dest >> wt;
		g.addEdge(src, dest, wt);
	}

	cout << g.bellman_ford_for_all_components();
}

int main() {
	solve();
	return 0;
}

// 6 7 0
// 3 2 6
// 5 3 1
// 0 1 5
// 1 5 -3
// 1 2 -2
// 3 4 -2
// 2 4 3