// Given a DAG, find the topological order using bfs() traversal

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

	void bfs(vector<bool> &visited) {
		vector<int> indegree(V, 0);

		// calculating the indegree of each node
		for (int i = 0; i < V; i++) {
			for (int neighbour : adjList[i])
				indegree[neighbour]++;
		}

		queue<int> q;

		// Idea is to start with those which have 0 indegrees/dependencies
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0)
				q.push(i);
		}

		while (!q.empty()) {
			int currNode = q.front();
			q.pop();

			// Solve this dependency
			cout << currNode << " ";

			// Once solved reduce the indegrees of neighbour which has currNode as depencency
			for (int neighbour : adjList[currNode]) {
				indegree[neighbour]--;

				if (indegree[neighbour] == 0)
					q.push(neighbour);
			}
		}
	}

	void topological_bfs() {
		vector<bool> visited(V, false);
		bfs(visited);
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
	g.topological_bfs();
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