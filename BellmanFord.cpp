#include<bits/stdc++.h>
using namespace std;

#define INF 99999

vector<int> bellmanFord(vector<vector<int>> &graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INF);
    dist[src] = 0;
    for(int i = 0; i < V - 1; i++) {
        for(int u = 0; u < V; u++) {
            for(int v = 0; v < V; v++) {
                if(graph[u][v] != INF) { // Means there is an edge from u to v
                    if(dist[u] + graph[u][v] < dist[v]) {
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
        }
    }
    return dist;
}