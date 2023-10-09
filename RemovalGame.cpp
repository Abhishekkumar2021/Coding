#include<bits/stdc++.h>
using namespace std;

// maximum possible score for the first player
long long maxScore(int left, int right, vector<int> &arr, vector<vector<long long>> &dp){
    if(left > right) return 0;

    if(dp[left][right] != -1) return dp[left][right];

    // When there is luck involved always assume that luck is against you
    long long x = arr[left] + min(maxScore(left+2, right, arr, dp), maxScore(left+1, right - 1, arr, dp)); 
    long long y = arr[right] + min(maxScore(left+1, right-1, arr, dp), maxScore(left, right - 2, arr, dp));
    return dp[left][right] = max(x, y);
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<vector<long long>> dp(n, vector<long long>(n, -1));
    cout << maxScore(0, n-1, arr, dp) << "\n";
    return 0;
}
