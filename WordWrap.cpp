#include<bits/stdc++.h>
using namespace std;

// recursive solution
int minCost(vector<int> &arr, int width, int idx, int n){
    if(idx>=n) return 0;
    int sum = 0;
    int ans = INT_MAX;
    for(int i=idx; i<n; i++){
        sum += arr[i];
        int covered = sum + (i-idx);
        if(covered <= width){
            if(i==n-1) ans = 0;
            else ans = min(ans, (width-covered)*(width-covered) + minCost(arr, width, i+1, n));
        }
        else break;
    }
    return ans;
}

int minCost(vector<int> &arr, int width){
    int n = arr.size();
    vector<int> dp(n, 0);
    for(int i=n-2; i>=0; i--){
        dp[i] = INT_MAX;
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            int covered = sum + (j-i);
            if(covered <= width){
                if(j==n-1) dp[i] = 0;
                else dp[i] = min(dp[i], (width-covered)*(width-covered) + dp[j+1]);
            }
            else break;
        }
    }
    return dp[0];
}


int main(){
    vector<int> len = {3, 2, 2, 5};
    int width = 6;
    cout<<minCost(len, width, 0, len.size());
    return 0;
}