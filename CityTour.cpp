#include<bits/stdc++.h>
using namespace std;

int ways(int rem, int mask, int n, vector<vector<int>> &dp){
    if(rem == 0) return 1;
    if(dp[rem][mask] != -1) return dp[rem][mask];
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(((mask>>i) & 1)==0){
            // Either of previous or next should be already visited then only i can visit this city
            if((i-1>=1 && ((mask>>(i-1)) & 1)==true) || (i+1<=n && ((mask>>(i+1)) & 1)==true)){
                ans += ways(rem-1, mask | (1<<i), n, dp);
            }
        }
    }
    return dp[rem][mask] = ans;
}

int cityTour(int n, vector<int> &visited){
    vector<bool> vis(n+1, false);
    vis[0] = true;
    int mask = 0;
    for(auto &it: visited) mask = mask | (1<<it);
    vector<vector<int>> dp(n+1, vector<int>(1<<(n+1), -1));
    return ways(n-visited.size(), mask, n, dp);
}