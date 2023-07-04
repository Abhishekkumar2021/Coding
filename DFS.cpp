#include<bits/stdc++.h>
using namespace std;

void dfs(int src, vector<int> adj[], int n){
    // Iterative function to perform DFS
    stack<int> st;
    st.push(src);
    vector<bool> vis(n, false);
    vis[src] = true;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        cout<<node<<" ";
        for(auto it: adj[node]){
            if(!vis[it]){
                st.push(it);
                vis[it] = true;
            }
        }
    }
}