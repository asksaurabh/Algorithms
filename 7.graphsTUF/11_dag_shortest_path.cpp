// Given a directed acyclic path with weights, find the shortest path of each node from the source.

// Topological Sorting basically sorts the vertices of graph in increasing order of their dependencies(by dependencies of vertex we mean indegree of a edge) or their indegree and Since shortest path between source vertex and a particular vertex should involve minimum intermediate edges hence finding topological sort first for computing shortest path makes sense becaues topological sort arranges the vertices in increasing order of their indegree.

#include <bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	vector<pair<int, int>> *adjList;

public:
	Graph(int V) {
		this->V = V;
		adjList = new vector<pair<int, int>> [V];
	}

	void addEdge(int src, int dest, int wt, bool isundirected = true) {
		adjList[src].push_back({dest, wt});
	}

	void printAdjList() {
		for (int v = 0; v < V; v++) {
			cout << "Vertex " << v << " : ";
			for (auto neighbour : adjList[v])
				cout << "(" << neighbour.first << ", " << neighbour.second << ")";
			cout << "\n";
		}
	}

	void topodfs(int node, vector<bool> &visited, stack<int> &st) {
		visited[node] = true;

		// Call for its neighbours
		for (auto neighbour : adjList[node]) {
			if (visited[neighbour.first] == false) {
				topodfs(neighbour.first, visited, st);
			}
		}

		// Dependencies finished, Now push it
		st.push(node);
		return;
	}

	void shortestPath(int source) {
		vector<bool> visited(V, false);
		stack<int> st;

		// Find the topological order of the graph
		for (int i = 0; i < V; i++) {
			if (visited[i] == false)
				topodfs(i, visited, st);
		}

		// Create a distance array to store the distances from the source
		vector<int> distance(V, INT_MAX);
		distance[source] = 0;

		// Now traverse through the topo order and find the distances
		while (!st.empty()) {
			int curr_node = st.top();
			st.pop();

			// If u have reached this node before from source
			if (distance[curr_node] != INT_MAX) {

				// traverse over the neighbours ahead
				for (auto neigh : adjList[curr_node]) {
					if (distance[neigh.first] > distance[curr_node] + neigh.second)
						distance[neigh.first] = distance[curr_node] + neigh.second;
				}
			}

		}

		for (int i = 0; i < V; i++) {
			cout << "Sou: " << source << " Dest: " << i << " Dist: " << distance[i] << "\n";
		}
	}
};

void solve() {
	int V, E, source;
	cin >> V >> E >> source;

	Graph g(V);

	for (int i = 0; i < E; i++) {
		int src, dest, wt;
		cin >> src >> dest >> wt;

		g.addEdge(src, dest, wt);
	}

	g.printAdjList();
	g.shortestPath(source);
}

int main() {
	solve();
	return 0;
}

// 6 7 0
// 0 1 2
// 0 4 1
// 1 2 3
// 4 2 2
// 2 3 6
// 4 5 4
// 5 3 1