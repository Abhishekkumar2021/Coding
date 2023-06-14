#include<bits/stdc++.h>
using namespace std;

int minimumDeleteSum(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    int sum = 0;
    for(int i=0; i<=m; i++){
        dp[0][i] = sum;
        sum += s2[i];
    }
    sum = 0;
    for(int i=0; i<=n; i++){
        dp[i][0] = sum;
        sum += s1[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i][j-1] + s2[j-1], dp[i-1][j] + s1[i-1]);
        }
    }

    return dp[n][m];
}