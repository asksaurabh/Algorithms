// Check cycle in an undirected graph using DSU
// We r goin to store the edge list representation of graph

// REMEMBER: UNDIRECTED GRAPH

#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	vector<pair<int, int>> edgeList;

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int src, int dest) {
		edgeList.push_back({src, dest});
	}

	// Returns the set(super leader) to which element belongs to
	// PATH COMPRESSION ALGORITHM
	int find(int node, int *parent) {
		if (parent[node] == -1)
			return node;

		return parent[node] = find(parent[node], parent);
	}

	// Merges different sets
	void Union(int node1, int node2, int *parent, int *rank) {
		int set1 = find(node1, parent);
		int set2 = find(node2, parent);

		if (set1 != set2) {

			// Merge by seeing rank
			if (rank[set1] < rank[set2]) {
				parent[set1] = set2;
				rank[set2] += rank[set1];
			}
			else {
				parent[set2] = set1;
				rank[set1] += rank[set2];
			}
		}
	}

	// Returns true if cycle is present, otherwise false
	bool containsCycle() {
		int *parent = new int[V];
		int *rank = new int[V];
		for (int i = 0; i < V; i++) {
			parent[i] = -1;          // Everyone is parent of itself
			rank[i] = 1;             // Everyone has size 1
		}

		// Iterate over the edgeList
		for (auto edge : edgeList) {
			int node1 = edge.first, node2 = edge.second;

			// Find if the lie in same set
			int set1 = find(node1, parent);
			int set2 = find(node2, parent);

			if (set1 == set2) {
				cout << "Same parent " << set1 << " and " << set2 << "\n";
				return true;
			}

			Union(node1, node2, parent, rank);
		}

		delete [] parent;
		delete [] rank;
		return false;
	}
};

void solve() {
	int V, E;
	cin >> V >> E;

	Graph g(V + 1);
	for (int i = 0; i < E; i++) {
		int src, dest;
		cin >> src >> dest;
		g.addEdge(src, dest);
	}

	cout << g.containsCycle();
}

int main() {
	solve();
	return 0;
}

// 4 4
// 1 2
// 2 3
// 3 4
// 4 1