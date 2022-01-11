// Given a DAG, find the topological order using dfs() traversal

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
		for (int v = 0; v < V; v++) {
			cout << "Vertex " << v << " : ";
			for (int neighbour : adjList[v])
				cout << neighbour << " ";
			cout << "\n";
		}
	}

	void dfs(int node, vector<bool> &visited, stack<int> &st) {
		visited[node] = true;

		// Check if it has neighbbours
		for (int neighbour : adjList[node]) {
			if (visited[neighbour] == false) {
				dfs(neighbour, visited, st);
			}
		}

		st.push(node);
		return;
	}

	void topological_dfs() {
		vector<bool> visited(V, false);
		stack<int> st;

		for (int v = 0; v < V; v++) {
			if (visited[v] == false) {
				dfs(v, visited, st);
			}
		}

		while (!st.empty()) {
			cout << st.top() << " ";
			st.pop();
		}
	}
};

void solve() {
	int V, E;
	cin >> V >> E;

	Graph g(V);

	for (int i = 0; i < E; i++) {
		int src, dest;
		cin >> src >> dest;

		g.addEdge(src, dest);
	}

	g.printAdjList();
	g.topological_dfs();
}

int main() {
	solve();
	return 0;
}

// 6 6
// 5 0
// 4 0
// 5 2
// 2 3
// 3 1
// 4 1