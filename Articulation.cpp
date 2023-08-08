#include<bits/stdc++.h>
using namespace std;

// Print all the articulation points in a graph
// An articulation point is a vertex removing which increases the number of connected components in the graph

// Time Complexity: O(V+E)

// Algorithm:
// 1. Do a DFS traversal of the graph and keep track of the discovery time of each vertex.
// 2. Initialize the low value of each vertex to its discovery time.
// 3. If the destination vertex is not visited, make a recursive call to it.
// 4. If the destination vertex is visited, check if the destination vertex is not the parent of the source vertex.
// 5. If the destination vertex is not the parent of the source vertex, update the low value of the source vertex to the minimum of its low value and the discovery time of the destination vertex.
// 6. If the source vertex is the root of the DFS tree and it has more than one child, then it is an articulation point.

void dfs(int src, vector<int> adj[], vector<int> &disc, vector<int> &low, vector<int> &parent, vector<bool> &marked, int &time) {
    disc[src] = low[src] = time;
    time++;
    int children = 0;
    for(auto x: adj[src]) {
        children++;
        if(disc[x] == -1) {
            parent[x] = src;
            dfs(x, adj, disc, low, parent, marked, time);
            low[src] = min(low[src], low[x]);

            // If low value of x is greater than discovery value of src, then it is an articulation point because there is no other way to reach x from src other than this edge
            if(parent[src] != -1 && low[x] >= disc[src]) {
                marked[src] = true;
            }
        }
        else if(x != parent[src]) {
            low[src] = min(low[src], disc[x]);
        }
    }
    if(parent[src] == -1 && children > 1) {
        marked[src] = true;
    }
}

vector<int> articulationPoints(int V, vector<int>adj[]) {
    vector<int> disc(V, -1), low(V, -1), parent(V, -1);
    vector<bool> marked(V, false);

    int time = 0;
    for(int i=0; i<V; i++) {
        if(disc[i] == -1) {
            dfs(i, adj, disc, low, parent, marked, time);
        }
    }

    vector<int> ans;
    for(int i=0; i<V; i++) {
        if(marked[i]) {
            ans.push_back(i);
        }
    }
    return ans;
}