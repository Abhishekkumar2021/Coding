#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

bool check(int mask, int i){
    return (mask & (1<<i));
}

void generateNext(int mask, int row, int n, int next, vector<int> &masks){
    if(row >= n){
        masks.push_back(next);
        return;
    }

    // If the current bit is set in the current mask then the next mask definitely going to contain 0
    if(check(mask, row) == 1){
        // No tile
        generateNext(mask, row+1, n, next, masks);
    }else{
        // If the are two consecutive 0 then there are two ways to fill
        // 1. Horizontal
        // 2. Vertical
        if(row != n-1 && (check(mask, row) == 0) && (check(mask, row+1) == 0)){
            // Vertical Tile
            generateNext(mask, row+2, n, next, masks);
            // Horizontal Tile
            generateNext(mask, row+1, n, next | (1 << row), masks);
        }else{
            // Horizontal Tile
            generateNext(mask, row+1, n, next | (1 << row), masks);
        }
    }
}

long long numWays(int col, int mask, int n, int m, vector<vector<long long>> &dp){
    if(col == m){
        if(mask  == 0) return 1;
        return 0;
    }

    if(dp[col][mask] != -1) return dp[col][mask];
  
    // Now we are at col, so we will first try to generate all the possible next 
    long long ans = 0;
    vector<int> masks;
    generateNext(mask, 0, n, 0, masks);
    for(auto &next: masks){
        ans = (ans + numWays(col+1, next, n, m, dp))%mod;
    }
    return dp[col][mask] = ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> dp(m, vector<long long>(1<<n, -1));
    // cout << numWays(0, 0, n, m, dp) << "\n";

    // Tabulation
    for(int col = m; col>=0; col--){
        for(int mask = 0; mask < (1<<n); mask++){
            if(col == m){
                dp[col][mask] = (mask == 0);
            }
            else{
                long long ans = 0;
                // generate all next masks
                vector<int> masks;
                generateNext(mask, 0, n, 0, masks);
                for(auto &next: masks){
                    ans = (ans + dp[col+1][next])%mod;
                }
                return dp[col][mask] = ans;
            }
        }
    }
    cout << dp[0][0] << "\n";
}
