// Given a directed graph, dtect if there is any cycle using bfs

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

	bool kahnBfs(vector<bool> &visited, vector<int> &indegree) {

		queue<int> q;
		vector<int> topo;

		// Push all those nodes which have indegree 0
		for (int i = 0; i < V; i++)
			if (indegree[i] == 0)
				q.push(i);

		while (!q.empty()) {
			int currNode = q.front();
			q.pop();

			// Complete the task
			topo.push_back(currNode);

			// remove dependencies on neighbours which have current node as dependency
			for (int neighbour : adjList[currNode]) {
				indegree[neighbour]--;

				if (indegree[neighbour] == 0)
					q.push(neighbour);
			}
		}

		// If topo sort is not equal to total vertices, that means there are some vertices which have indegrees > 0 still present which is only possible if the graph is cyclic

		if (topo.size() == V)
			return false;

		return true;
	}

	// idea is if u r able to generate a topo sort, then no cycle else cycle present.
	bool isCycle() {
		vector<bool> visited(V, false);
		vector<int> indegree(V, 0);

		for (int i = 0; i < V; i++) {
			for (int neighbour : adjList[i])
				indegree[neighbour]++;
		}

		return kahnBfs(visited, indegree);
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
	cout << g.isCycle();
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