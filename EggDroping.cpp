#include<bits/stdc++.h>
using namespace std;

int minDropping(int eggs, int floors){
    if(floors <= 1 || eggs == 1) return floors;
    
    int mini = INT_MAX;
    for(int f = 1; f<=floors; f++){
        int breaked = minDropping(eggs - 1, f - 1);
        int unbreaked = minDropping(eggs, floors - f);

        // Max is for the worst case
        int temp = 1 + max(breaked, unbreaked);

        // Min for minimum out of all worst cases
        mini = min(mini, temp);
    }
    return mini;
}

int minTrials(int e, int f){
    vector<vector<int>> dp(e+1, vector<int>(f+1, INT_MAX));

    for(int eggs = 1; eggs <= e; eggs++){
        for(int floors = 0; floors <= f; floors++){
            // base cases
            if(eggs == 1 || floors <= 1) dp[eggs][floors] = floors;
            else{
                // We have to do this work in logN time, where N = number of floors
                // for(int k = 1; k <= floors; k++){
                //     int breaked = dp[eggs - 1][k - 1];
                //     int unbreaked = dp[eggs][floors - k];
                //     // Best of the worst
                //     dp[eggs][floors] = min(dp[eggs][floors], 1 + max(breaked, unbreaked));
                // }

                int l = 1, r = floors;
                int mini = INT_MAX;
                while(l <= r){
                    int mid = l + (r - l)/2;
                    int breaked = dp[eggs - 1][mid - 1];   // always non-decreasing curve
                    int unbreaked = dp[eggs][floors - mid];  // always non-increasing curve

                    mini = min(mini, 1 + max(breaked, unbreaked));

                    if(breaked >= unbreaked){
                        r = mid - 1;
                    }else{
                        l = mid + 1;
                    }
                }
                dp[eggs][floors] = mini;
            }
        }
    }

    return dp[e][f];
}