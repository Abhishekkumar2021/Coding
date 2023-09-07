#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class element{
    public:
    int zeros;
    int ones;
    element(){
        ones = 0;
        zeros = 0;
    }
};

int maxSubset(vector<element> &arr, int size, int m, int n, vvvi &dp){
    // base case
    if(size == 0) return 0;
    if(n==0 && m==0) return 0;

    if(dp[size][m][n] != -1) return dp[size][m][n];

    // If we can't take current element
    if(arr[size-1].zeros > m || arr[size-1].ones > n){
        int notTaken = maxSubset(arr, size-1, m, n, dp);
        return dp[size][m][n] = notTaken;
    }

    // Current element can be taken then we have two choices 
    // Either we take
    // Either we don't take
    int taken = 1 + maxSubset(arr, size-1, m-arr[size-1].zeros, n-arr[size-1].ones, dp);
    int notTaken = maxSubset(arr, size-1, m, n, dp);
    return dp[size][m][n] = max(taken, notTaken);
}


int maxSubset(vector<element> &arr, int k, int zeros, int ones){
    vvi curr(zeros+1, vi(ones+1, 0)), prev(zeros+1, vi(ones+1, 0));
    for(int size = 1; size <= k; size++){
        for(int m = 0; m<=zeros; m++){
            for(int n = 0; n <= ones; n++){
                if(m==0 && n==0) curr[m][n] = 0;
                else{
                    // If we can't take current element
                    if(arr[size-1].zeros > m || arr[size-1].ones > n){
                        int notTaken = prev[m][n];
                        curr[m][n] = notTaken;
                    }else{
                        // Current element can be taken then we have two choices 
                        // Either we take
                        // Either we don't take
                        int taken = 1 + prev[m-arr[size-1].zeros][n-arr[size-1].ones];
                        int notTaken = prev[m][n];
                        curr[m][n] = max(taken, notTaken);
                    }
                }
            }
        }
        prev = curr;
    }
    return curr[zeros][ones];
}

int findMaxForm(vector<string>& strs, int m, int n) {
    int k = strs.size();
    vector<element> arr(k);
    for(int i = 0; i<k; i++){
        for(auto &ch : strs[i]){
            if(ch == '1') arr[i].ones++;
            else arr[i].zeros++;
        }
    }
    vvvi dp(k + 1, vvi(m+1, vi(n+1, -1)));
    int ans = maxSubset(arr, k, m, n, dp);
    return ans;
}