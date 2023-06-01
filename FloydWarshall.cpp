#include<bits/stdc++.h>
using namespace std;

#define INF 99999

vector<vector<int>> floydWarshall(vector<vector<int>> &graph) {
    int V = graph.size();
    vector<vector<int>> dist(V, vector<int>(V, INF));
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for(int k = 0; k < V; k++) {
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j]; 
                }
            }
        }
    }
    return dist;
}