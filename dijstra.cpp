#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int to;
    int weight;
};

void dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& distances) {
    int numVertices = graph.size();
    distances.assign(numVertices, INT_MAX);
    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentDist > distances[currentNode])
            continue;

        for (const Edge& edge : graph[currentNode]) {
            int neighbor = edge.to;
            int weight = edge.weight;
            int newDistance = distances[currentNode] + weight;

            if (newDistance < distances[neighbor]) {
                distances[neighbor] = newDistance;
                pq.push(make_pair(newDistance, neighbor));
            }
        }
    }
}

int main() {
    int numVertices, numEdges, startVertex;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;

    vector<vector<Edge>> graph(numVertices);

    cout << "Enter the edges (from to weight):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight}); 
    }

    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    vector<int> distances;
    dijkstra(graph, startVertex, distances);

    cout << "Shortest distances from vertex " << startVertex << " to all other vertices:" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": ";
        if (distances[i] == INT_MAX) {
            cout << "INF" << endl;
        } else {
            cout << distances[i] << endl;
        }
    }

    return 0;
}


//sample input :
// Enter the number of vertices and edges: 5 7
// Enter the edges (from to weight):
// 0 1 4
// 0 2 1
// 1 2 2
// 1 3 5
// 2 3 8 
// 2 4 10
// 3 4 2
// Enter the starting vertex: 0
// Shortest distances from vertex 0 to all other vertices:
// Vertex 0: 0
// Vertex 1: 3
// Vertex 2: 1
// Vertex 3: 8
// Vertex 4: 10
