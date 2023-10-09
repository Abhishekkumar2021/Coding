#include<bits/stdc++.h>
using namespace std;

long long f(int idx, int prev,  int n, int m, vector<int> &arr, vector<vector<int>> &dp){
    if(idx == n) return 1;

    if(dp[idx][prev] != -1) return dp[idx][prev];

    if(arr[idx] != 0){
        if(idx == 0) return dp[idx][prev] = f(idx+1, arr[idx],  n, m, arr, dp);
        if(abs(arr[idx] - prev) <= 1) return dp[idx][prev] = f(idx+1, arr[idx], n, m, arr, dp);
        return dp[idx][prev] = 0;
    }
    long long ans = 0;
    const int mod = 1e9 + 7;
    
    if(idx != 0){
        for(int i=-1; i<=1; i++){
            if(prev + i < 1 || prev + i > m) continue;
            ans = (ans + f(idx+1, prev + i,  n, m, arr, dp))%mod;
        }
    }else{
        for(int i=1; i<=m; i++){
            ans = (ans + f(idx+1, i, n, m, arr, dp))%mod;
        }
    }
    
    return dp[idx][prev] = ans;
    
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout << f(0, 0, n, m, arr, dp) << "\n";
    return 0;
}
