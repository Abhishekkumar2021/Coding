#include<bits/stdc++.h>
using namespace std;

bool isSubset(vector<int> &arr, int target){
    int n = arr.size();
    bool dp[n+1][target+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=target; j++){
            if(i==0 && j==0){
                dp[i][j] = true;
            }
            else if(i==0){
                dp[i][j] = false;
            }
            else if(j==0){
                dp[i][j] = true;
            }
            else{
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    return dp[n][target];
}

int minSubsetSumDifference(vector<int>& arr, int n){
    // use inbuilt sum function
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int target = sum/2;
    bool dp[n+1][target+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=target; j++){
            if(i==0 && j==0){
                dp[i][j] = true;
            }
            else if(i==0){
                dp[i][j] = false;
            }
            else if(j==0){
                dp[i][j] = true;
            }
            else{
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

    int mini = INT_MAX;
    for(int i=0; i<=sum/2; i++){
        if(dp[n][i]){
            mini = min(mini, sum-2*i);
        }
    }
    return mini;
}