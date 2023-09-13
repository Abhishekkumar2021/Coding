#include<bits/stdc++.h>
using namespace std;

int minCost(const vector<int> &required, const vector<int> &filling, const vector<int> &cost){
    const int INF = 1e7;
    int n = filling.size();
    int m = required.size();
    int target = *max_element(required.begin(), required.end());
    vector<int> curr(target+1, INF), prev(target+1);

    // base cases
    // if(target == 0) return 0;
    // if(n==0) return INF;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=target; j++){
            if(j==0) curr[j] = 0;
            else if(i==0) curr[j] = INF;
            else if(filling[i-1] <= j) curr[j] = min(prev[j], cost[i-1] + curr[j - filling[i-1]]);
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    int ans = 0;
    for(int i=0; i<m; i++){
        ans += curr[required[i]];
    }
    return ans;
}