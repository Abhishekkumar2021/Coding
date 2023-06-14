#include<bits/stdc++.h>
using namespace std;

string LCS(string x, string y){
    int n = x.length();
    int m = y.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int i = n, j = m;
    string ans = 0;
    while(i>0 && j>0){
        if(x[i-1] == y[j-1]){
            ans.push_back(x[i-1]);
        }
        else if(dp[i][j-1] > dp[i-1][j]){
            j--;
        }
        else{
            i--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}