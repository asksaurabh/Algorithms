#include <bits/stdc++.h>
using namespace std;

class Graph {

	int V;
	vector<pair<int, int>> *adjList;
public:
	Graph(int V) {
		this->V = V;
		adjList = new vector<pair<int, int>> [V];
	}

	void addEdge(int src, int dest, int wt) {
		adjList[src].push_back({dest, wt});
		adjList[dest].push_back({src, wt});
	}

	// Build a MST and return min cost
	int prim_mst(int source) {

		// Build a min heap to decide which active edge to choose next
		// Stores {wt, dest}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minH;

		// Make a boolean array to decide whether node is included in MST or not
		vector<bool> visited(V, false);
		int minCost = 0;

		// Start with source node 0
		minH.push({0, source});            // Wt from source to source is 0

		while (!minH.empty()) {

			// Pick out an active edge with minimum wt.
			auto bestEdge = minH.top();
			minH.pop();

			// Find out whether this node is visited or not
			int node = bestEdge.second;
			int wt = bestEdge.first;

			if (visited[node])
				continue;

			// Else select the edge and add its cost
			visited[node] = true;
			minCost += wt;

			// Add the new active adges of node in the queue
			for (auto neighbour : adjList[node]) {
				if (visited[neighbour.first] == false) {
					minH.push({neighbour.second, neighbour.first});
				}
			}
		}

		return minCost;
	}
};

void solve() {
	int V, E;
	cin >> V >> E;

	Graph g(V);
	for (int i = 0; i < E; i++) {
		int src, dest, wt;
		cin >> src >> dest >> wt;

		g.addEdge(src, dest, wt);
	}

	cout << g.prim_mst(0);
}


int main() {
	solve();
	return 0;
}

// 4 6
// 0 1 1
// 0 2 2
// 1 2 2
// 0 3 2
// 1 3 3
// 2 3 3