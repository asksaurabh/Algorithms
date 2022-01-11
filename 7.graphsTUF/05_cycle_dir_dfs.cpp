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

	void addEdge(int src, int dest, bool isundirected = false) {
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

	bool dfs(int node, vector<bool> &visited, vector<bool> &currPath) {
		visited[node] = true;
		currPath[node] = true;  // Adding node to current dfs call path

		// Check on neighbours
		for (int neighbour : adjList[node]) {
			if (visited[neighbour] == false) {
				bool isCyclePresentInNeighbour = dfs(neighbour, visited, currPath);
				if (isCyclePresentInNeighbour)
					return true;
			}

			// If neighbour is visited and is in our curr call path
			else if (visited[neighbour] == true and currPath[neighbour] == true)
				return true;
		}

		// CLearing our current Path stack if dfs call is over
		currPath[node] = false;
		return false;
	}

	bool isCycle() {
		vector<bool> visited(V, false);
		vector<bool> currPath(V, false);

		for (int i = 1; i < V; i++) {
			if (visited[i] == false) {
				if (dfs(i, visited, currPath) == true)
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

// 3 3
// 1 2
// 2 3
// 1 3