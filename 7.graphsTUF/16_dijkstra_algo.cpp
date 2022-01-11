// Find the shortest path from source to every other node in a weighted undirected graph. Given the weights are always positive. DIJKSTRA's ALGORITHM
// Weights can't be negative here.

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

	void addEdge(int src, int dest, int wt) {
		adjList[src].push_back({dest, wt});
		adjList[dest].push_back({src, wt});
	}

	void printAdjList() {
		for (int i = 0; i < V; i++) {
			cout << "Vertex " << i << " : ";
			for (auto pr : adjList[i]) {
				cout << "(" << pr.first << "," << pr.second << ")";
			}
			cout << endl;
		}
	}

	// Returns the shortest path btw source and destination
	int dijkstra(int user_src, int user_dest) {

		// Stores {wt, dest}
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >minH;
		vector<int> distance(V, INT_MAX);

		// Initialize source
		distance[user_src] = 0;
		minH.push({0, user_src});

		while (!minH.empty()) {
			auto node = minH.top();
			minH.pop();

			int dest = node.second;
			int distTillNow = node.first;

			// Iterate over the neighbours of dest
			for (auto nghbrPair : adjList[dest]) {

				int neighbour = nghbrPair.first;
				int neighbour_dist = nghbrPair.second;

				if (distTillNow + neighbour_dist < distance[neighbour]) {

					distance[neighbour] = distTillNow + neighbour_dist;
					minH.push({distance[neighbour], neighbour});

				}

			}
		}

		// Single source shprtest distance to all other nodes from user_source
		for (int i = 0; i < V; i++)
			cout << "Src: " << user_src << " Dest: " << i << " Dist: " << distance[i] << "\n";

		return distance[user_dest];
	}
};

void solve() {

	int V, E, source, destination;
	cin >> V >> E >> source >> destination;

	Graph g(V);
	for (int i = 0; i < E; i++) {
		int src, dest, wt;
		cin >> src >> dest >> wt;

		g.addEdge(src, dest, wt);
	}

	g.printAdjList();
	cout << g.dijkstra(source, destination);
}


int main() {

	solve();
	return 0;
}

// 5 6 0 4
// 0 1 1
// 1 2 1
// 0 3 7
// 0 2 4
// 3 2 2
// 3 4 3