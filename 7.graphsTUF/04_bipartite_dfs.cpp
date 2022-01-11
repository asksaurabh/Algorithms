// Given an undirected graph, Tell if the graph is bipartite or not.

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

	bool dfs(int node, int node_parent, int color, vector<int> &visited) {

		visited[node] = color;

		// Look in the neighbours
		for (int neighbour : adjList[node]) {
			if (visited[neighbour] == 0) {
				bool isNeighbourBipartite = dfs(neighbour, node, 3 - color, visited);
				if (isNeighbourBipartite == false)
					return false;
			}

			else if (neighbour != node_parent and visited[neighbour] == color) {
				return false;
			}
		}

		return true;
	}

	bool isBipartite() {
		vector<int> visited(V, 0);
		// visited[x] -> 0 == not visited, visited[x] -> 1 == visited and color 1, ....

		for (int v = 1; v < V; v++) {
			if (visited[v] == 0) {
				if (dfs(v, -1, 2, visited) == false)
					return false;
			}
		}

		return true;
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
	cout << g.isBipartite();
}

int main() {
	solve();
	return 0;
}

// 5 5
// 1 2
// 2 3
// 3 4
// 4 5
// 5 1