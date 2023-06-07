#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &weight, vector<int> &value, int w){
    int n = weight.size();
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(weight[i-1]<=j){
                dp[i][j] = max(value[i]+dp[i][j-weight[i-1]],dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
            
        }
    }
    return dp[n][w];
}