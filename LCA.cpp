#include<bits/stdc++.h>
using namespace std;

class Solution{
    int n, q;
    int LGN;
    vector<int> par;
    vector<int> level;
    vector<vector<int>> adj;
    vector<vector<int>> up;
    public:
    void init(){
        LGN = 0;
        cin >> n >> q;
        par.resize(n+1, -1);
        level.resize(n+1, 0);
        adj.resize(n+1);
        for(int i=0; i<=n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // calculate LGN
        while((1<<LGN) <= n) LGN++;

        // Resizing up
        up.resize(LGN, vector<int>(n+1));

        // Call dfs on 1(root) and fill all the required values
        vector<bool> vis(n+1, false);
        dfs(1, vis);
    }

    void dfs(int node, vector<bool> &vis){
        vis[node] = true;
        for(auto &child: adj[node]){
            if(!vis[child]){
                par[child] = node;
                level[child] = level[node] + 1;
                dfs(child, vis);
            }
        }

        // Filling up up for the current node
        for(int i = 0; i<LGN; i++){
            if(i==0) up[0][node] = par[node];
            else if(up[i-1][node] != -1) up[i][node] = up[i-1][up[i-1][node]];
            else up[i][node] = -1;
        }
    }

    int KthAncestor(int node, int k){
        if(k > level[node]) return -1;
        for(int i=0; i<LGN; i++){
            if(k & (1<<i)) node = up[i][node];
        }
        return node;
    }

    void query(){
        while(q--){
            int node, k;
            cin >> node >> k;
            cout << KthAncestor(node, k) << "\n";
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.init();
    return 0;
}
