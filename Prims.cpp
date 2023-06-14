#include<bits/stdc++.h>
using namespace std;

void prims(vector<int> adj[], int n){
    vector<bool> visited(n, false);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    // {weight, node, parent}
    pq.push({0, 0, -1});
    int cost = 0;
    while(!pq.empty()){
        vector<int> curr = pq.top();
        pq.pop();
        if(visited[curr[1]]) continue;
        visited[curr[1]] = true;
        cost += curr[0];
        if(curr[2] != -1) cout << curr[2] << " " << curr[1] << endl;
        for(int i = 0; i < adj[curr[1]].size(); i++){
            if(!visited[adj[curr[1]][i]]){
                pq.push({adj[curr[1]][i], curr[1], adj[curr[1]][i]});
            }
        }
    }
    
}