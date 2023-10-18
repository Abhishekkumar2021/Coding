/*
Given a directed tree of N nodes from 1 to N and N-1 Edges, For every node we have to find out that how many reversal we have to do so that we are able to reach to every node from that node.
Input:

8
1 2
2 4
2 3
1 5
7 5
6 5
6 8
*/


#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &dg, vector<bool> &vis){
    vis[node] = true;
    for(auto &child: dg[node]){
        if(!vis[child]){
            dfs(child, dg, vis);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> dg(n+1);
    vector<int> indegree(n+1, 0);
    for(int i=1; i<=n; i++){
        // Edge is from i ==> x
        // We have to reverse x ==> i
        int x;
        cin >> x;
        if(i == x) continue;
        indegree[i]++;
        dg[x].push_back(i);
    }
    
    // Toposort
    vector<int> topo;
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto &child: dg[node]){
            indegree[child]--;
            if(indegree[child] == 0) q.push(child);
        }
    }
    vector<bool> vis(n+1, false);
    dfs(1, dg, vis);
    int ans = 0;
    for(auto &x: topo){
        if(!vis[x]){
            ans++;
            dfs(x, dg, vis);
        }
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            ans++;
            dfs(i, dg, vis);
        }
    }
    cout << ans << "\n";
    return 0;
}
