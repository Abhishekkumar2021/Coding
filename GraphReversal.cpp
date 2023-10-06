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

class Solution{
    map<pair<int, int>, int> dp;
    vector<vector<int>> dg;
    vector<vector<int>> ug;
    int n;

    // DFS
    int dfs(int node, vector<bool> &vis){
        vis[node] = true;
        int ans = 0;
        for(auto &child: dg[node]){
            if(!vis[child]){
                ans += dfs(child, vis);
            }
        }

        // maybe some child are not reachable, so have to reverse the edge and call dfs on them 
        for(auto &child: ug[node]){
            if(!vis[child]){
                if(dp.find({node, child}) == dp.end()){
                    dp[{node, child}] = dfs(child, vis) + 1;   
                }
                ans += dp[{node, child}];
            }
        }

        return ans;
    }

    public:
    Solution(vector<vector<int>> dg, vector<vector<int>> ug){
        this->dg = dg;
        this->ug = ug;
        this->n = ug.size();
    }
    
    int numReversal(int node){
        vector<bool> vis(n, false);
        return dfs(node, vis);
    }
};



int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> dg(n+1);
    vector<vector<int>> ug(n+1);
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        dg[u].push_back(v);
        ug[u].push_back(v);
        ug[v].push_back(u);
    }
    Solution s(dg, ug);
    for(int i=1; i<=n; i++){
        cout << s.numReversal(i) << " ";
    }
    return 0;
}
