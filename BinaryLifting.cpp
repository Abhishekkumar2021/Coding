#include<bits/stdc++.h>
using namespace std;

// The question is to find the kth ancestor of a node : only valid in case of where the node values lies between 0 to N-1 like a graph
class TreeAncestor {
    int LogN;
    vector<vector<int>> dp;
public:
    TreeAncestor(int n, vector<int>& parent) {
        LogN = 0;
        while((1<<LogN) <= n) LogN++;
        dp.resize(LogN, vector<int>(n, -1));

        // Fill the dp array
        for(int i=0; i<n; i++) dp[0][i] = parent[i];

        for(int power = 1; power < LogN; power++){
            for(int node=0; node<n; node++){
                if(dp[power-1][node] == -1) continue;
                dp[power][node] = dp[power-1][dp[power-1][node]];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int ans = 0;
        for(int i=0; i<LogN; i++){
            if((k>>i) & 1){
                if(node == -1) return node;
                node = dp[i][node];
            }
        }
        return node;
    }
};