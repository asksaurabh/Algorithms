// Detect cycle in undirected graph using dfs() traversal
#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	vector<int> *adjList;

public:
	Graph(int V) {
		this->V = V;
		adjList = new vector<int> [V];
	}

	void addEdge(int src, int dest, bool isundirected = true) {
		adjList[src].push_back(dest);
		if (isundirected)
			adjList[dest].push_back(src);
	}

	void printAdjList() {
		for (int v = 1; v < V; v++) {
			cout << "Vertex " << v << " : ";
			for (int neighbour : adjList[v])
				cout << neighbour << " ";
			cout << "\n";
		}
	}

	bool dfs(int node, int node_parent, vector<bool> &visited) {
		visited[node] = true;

		// call dfs on its neighbours and see they contain cycle recursively
		for (int neighbour : adjList[node]) {

			if (visited[neighbour] == false) {
				bool isCyclePresentInNeighbour = dfs(neighbour, node, visited);
				if (isCyclePresentInNeighbour)
					return true;
			}

			else if (visited[neighbour] == true and node_parent != neighbour) {
				return true;
			}
		}

		return false;
	}

	bool isCycle() {
		vector<bool> visited(V + 1, false);
		for (int v = 1; v < V; v++) {
			if (visited[v] == false) {
				if (dfs(v, -1, visited))
					return true;
			}
		}

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

	g.printAdjList();
	cout << g.isCycle();
}

int main() {
	solve();
	return 0;
}

// 8 7
// 1 3
// 3 4
// 2 5
// 5 8
// 8 7
// 7 6
// 6 5