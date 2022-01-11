#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	vector<int> *adjList;

public:
	Graph (int v) {
		this->V = v;
		adjList = new vector<int> [V];
	}

	void addEdge(int src, int dest, bool isundirected = true) {
		adjList[src].push_back(dest);
		if (isundirected)
			adjList[dest].push_back(src);
	}

	void printAdjList() {
		for (int v = 0; v < V; v++) {
			cout << "Vertex " << v << ": " << " ";
			for (int neighbour : adjList[v]) {
				cout << neighbour << " ";
			}
			cout << "\n";
		}
	}

	void bfs_util(int src, vector<bool> &visited) {
		queue<int> q;
		q.push(src);
		visited[src] = true;

		while (!q.empty()) {
			int currNode = q.front();
			q.pop();

			cout << currNode << " ";

			// Now visit its adjacent nodes
			for (int neighbour : adjList[currNode]) {
				if (visited[neighbour] == false) {
					q.push(neighbour);
					visited[neighbour] = true;
				}
			}
		}
	}

	void bfs() {
		vector<bool> visited(V, false);
		for (int v = 0; v < V; v++) {
			if (visited[v] == false)
				bfs_util(v, visited);
		}
		cout << "\n";
	}

	void dfs_util(int node, vector<bool> &visited) {
		visited[node] = true;
		cout << node << " ";

		// call the dfs on its neighbours
		for (int neighbour : adjList[node]) {
			if (visited[neighbour] == false)
				dfs_util(neighbour, visited);
		}
	}

	void dfs() {
		vector<bool> visited(V, false);
		for (int v = 0; v < V; v++) {
			if (visited[v] == false)
				dfs_util(v, visited);
		}
		cout << "\n";
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
	g.bfs();
	g.dfs();
}

int main() {

	solve();

	return 0;
}

// IP:
// 5 6
// 0 1
// 1 2
// 2 3
// 3 4
// 4 0
// 0 3