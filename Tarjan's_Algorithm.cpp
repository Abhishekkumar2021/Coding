#include<bits/stdc++.h>
using namespace std;

// Print all the bridges in a graph
// A bridge is an edge removing which increases the number of connected components in the graph

// Time Complexity: O(V+E)

// Algorithm:
// 1. Do a DFS traversal of the graph and keep track of the discovery time of each vertex.
// 2. Initialize the low value of each vertex to its discovery time.
// 3. If the destination vertex is not visited, make a recursive call to it.
// 4. If the destination vertex is visited, check if the destination vertex is not the parent of the source vertex.
// 5. If the destination vertex is not the parent of the source vertex, update the low value of the source vertex to the minimum of its low value and the discovery time of the destination vertex.

// Code:
// Time Complexity: O(V+E)

void dfs(int src, vector<int> adj[], vector<int> &disc, vector<int> &low, vector<int> &parent, vector<vector<int>> &ans, int &time) {
    disc[src] = low[src] = time;
    time++;
    for(auto x: adj[src]) {
        if(disc[x] == -1) {
            parent[x] = src;
            dfs(x, adj, disc, low, parent, ans, time);
            low[src] = min(low[src], low[x]);

            // If low value of x is greater than discovery value of src, then it is a bridge because there is no other way to reach x from src other than this edge
            if(low[x] > disc[src]) {
                ans.push_back({src, x});
            }
        }
        else if(x != parent[src]) {
            low[src] = min(low[src], disc[x]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> ans;
    vector<int> adj[n];
    for(auto x: connections) {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }

    vector<int> disc(n, -1), low(n, -1), parent(n, -1);
    int time = 0;
    for(int i=0; i<n; i++) {
        if(disc[i] == -1) {
            dfs(i, adj, disc, low, parent, ans, time);
        }
    }
    return ans; 
}