#include<bits/stdc++.h>
using namespace std;

int ways(int n, int m, vector<vector<int>> &dp){
    if(n == m) return 0;
    if(n == 1) return m-1;
    if(m == 1) return n-1;

    if(dp[n][m] != -1) return dp[n][m];

    int ans = INT_MAX;
    // Horizontal cut
    for(int k=1; k<n; k++){
        ans = min(ans, 1 + ways(k, m, dp) + ways(n-k, m, dp));
    }
    for(int k=1; k<m; k++){
        ans = min(ans, 1 + ways(n, k, dp) + ways(n, m-k, dp));
    }
    return dp[n][m] =  ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i == 1) dp[i][j] = j - 1;
            else if(j == 1) dp[i][j] = i - 1;
            else if(i == j) dp[i][j] = 0;
            else{
                int ans = INT_MAX;
                // Horizontal cut
                for(int k=1; k<i; k++){
                    ans = min(ans, 1 + dp[k][j] + dp[i-k][j]);
                }
                for(int k=1; k<j; k++){
                    ans = min(ans, 1 + dp[i][k] + dp[i][j-k]);
                }
                dp[i][j] = ans;
            }
        }
    }
    cout << dp[n][m] << "\n";
    return 0;
}
