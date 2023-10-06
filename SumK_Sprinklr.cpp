#include<bits/stdc++.h>
using namespace std;

int ways(vector<int> &arr, int n, int curr, int sum, int k, vector<vector<int>> &dp){
    if(n==0) return curr > k && (sum-curr) > k;

    if(dp[n][curr] != -1) return dp[n][curr] != -1;

    // Take this into current set
    int a = ways(arr, n-1, curr + arr[n-1], sum, k, dp);

    // Take it into another set
    int b = ways(arr, n-1, curr, sum, k, dp);

    return dp[n][curr] = a + b;
}

int numWays(vector<int> &arr, int k){
    int n = arr.size();
    int sum = 0;
    for(int i=0; i<n; i++) sum += arr[i];
    vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
    return ways(arr, n, 0, sum, k, dp);
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout << numWays(arr, k) << endl;
    return 0;
}