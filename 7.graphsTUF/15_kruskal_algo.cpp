#include <bits/stdc++.h>
using namespace std;

class DSU {
	int *parent;
	int *rank;
public:
	DSU(int V) {
		parent = new int [V];
		rank = new int [V];

		// Initialize
		for (int i = 0; i < V; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int node) {
		if (parent[node] == -1)
			return node;

		return parent[node] = find(parent[node]);
	}

	void Union(int node1, int node2) {
		// FInd the set of both nodes
		int set1 = find(node1);
		int set2 = find(node2);

		if (set1 != set2) {
			if (rank[set1] >= rank[set2]) {
				parent[set2] = set1;
				rank[set1] += rank[set2];
			}
			else {
				parent[set1] = set2;
				rank[set2] += rank[set1];
			}
		}
	}
};

class Graph {

	int V;
	vector<vector<int>> edgeList;

public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int src, int dest, int wt) {
		edgeList.push_back({wt, src, dest});
	}

	// Returns the minimum cost of MST
	int kruskal_mst() {
		// Sort the edgeList based upon the weight
		sort(edgeList.begin(), edgeList.end());

		int minCost = 0;
		DSU d(V);

		// Iterate over edgeList and pick MST edges
		for (auto edge : edgeList) {
			int wt = edge[0];
			int src = edge[1];
			int dest = edge[2];

			// Find the set to which src and dest belong to
			int set1 = d.find(src);
			int set2 = d.find(dest);

			if (set1 != set2) {
				// Select the edge, unite them in mst and add its cost
				d.Union(src, dest);
				minCost += wt;
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

	cout << g.kruskal_mst();
}

int main() {
	solve();
	return 0;
}