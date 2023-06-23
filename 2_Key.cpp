#include<bits/stdc++.h>
using namespace std;
#define INF 10000000

int minSteps(int curr, int n, int clip, vector<vector<int>> &dp){
    if(curr==n) return 0;
    if(curr>n) return 1e5;

    /*
    2 keys are available:
    1. Copy All
    2. Paste
    2 Consecutive copy operations are not allowed
    */
    if(dp[curr][clip]!=-1) return dp[curr][clip];

    if(curr != clip){
        int copyAll = 1 + minSteps(curr, n, curr, dp);
        int paste = 1 + minSteps(curr+clip, n, clip, dp);
        return dp[curr][clip] = min(copyAll, paste);
    }
    else{
        int paste = 1 + minSteps(curr+clip, n, clip, dp);
        return dp[curr][clip] = paste;
    }

}

int minSteps(int n){
    if(n==1) return 0;
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    return 1 + minSteps(1, n, 1, dp);
}