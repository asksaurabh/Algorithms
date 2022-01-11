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

	bool bfs(int node, vector<int> &visited) {
		queue<pair<int, int>> q;
		q.push({node, -1});
		visited[node] = 1;

		while (!q.empty()) {
			int curr_node = q.front().first;
			int node_parent = q.front().second;
			q.pop();

			for (int neighbour : adjList[curr_node]) {
				if (visited[neighbour] == false) {
					q.push({neighbour, curr_node});
					visited[neighbour] = 3 - visited[curr_node];
				}

				else if (node_parent != neighbour && visited[curr_node] == visited[neighbour]) {
					return false;
				}
			}
		}

		return true;
	}

	bool isBipartite() {
		vector<int> visited(V, 0);
		// vector<int> color(V, -1);

		for (int v = 1; v < V; v++) {
			if (visited[v] == false) {
				if (bfs(v, visited) == false)
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

// 8 7
// 1 3
// 3 4
// 2 5
// 5 8
// 8 7
// 7 6
// 6 5