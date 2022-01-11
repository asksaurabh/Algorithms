// Given an unweighted undirected graph and a source, find the shortest path from source to all the other nodes using bfs.
// HAPPENS WHEN WEIGHTS ARE UNITY. (Imp condition)
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
		for (int i = 0; i < V; i++) {
			cout << "Vertex " << i << " : ";
			for (int neighbour : adjList[i])
				cout << neighbour << " ";
			cout << "\n";
		}
	}

	vector<int> bfs(int source, vector<bool> &visited) {
		queue<int> q;
		vector<int> distance(V, -1);

		q.push(source);
		visited[source] = true;
		distance[source] = 0;

		while (!q.empty()) {
			int currNode = q.front();
			q.pop();

			for (int neighbour : adjList[currNode]) {
				if (visited[neighbour] == false) {
					q.push(neighbour);
					visited[neighbour] = true;
					distance[neighbour] = distance[currNode] + 1;
				}
			}
		}

		return distance;
	}

	void shortestPath(int source) {
		vector<bool> visited(V, false);
		vector<int> sp = bfs(source, visited);

		for (int i = 0; i < V; i++) {
			cout << "Source: " << source << " Dest : " << i << " Distance: " << sp[i];
			cout << "\n";
		}
	}
};

void solve() {
	int V, E, source;
	cin >> V >> E >> source;

	Graph g(V);
	for (int i = 0; i < E; i++) {
		int src, dest;
		cin >> src >> dest;
		g.addEdge(src, dest);
	}


	g.printAdjList();
	g.shortestPath(source);
}

int main() {

	solve();
	return 0;
}

// 5 6 0
// 0 1
// 1 2
// 2 3
// 3 4
// 4 0
// 0 3