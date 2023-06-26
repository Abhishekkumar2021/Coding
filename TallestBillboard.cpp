#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isExist(vector<int> &arr, int n, int target, vector<int> & vis){
        if(target == 0) return true;
        if(n == 0) return false;
        if(vis[n-1] == 1) return isExist(arr, n-1, target, vis);

        if(arr[n-1] <= target){
            // include
            vis[n-1] = 1;
            if(isExist(arr, n-1, target-arr[n-1], vis)) return true;
            // exclude
            vis[n-1] = 0;
            return isExist(arr, n-1, target, vis);
        }
        return isExist(arr, n-1, target, vis);
    }

    int equalSum(vector<int> &arr, int n, int first, int second, map<pair<int, int>, int> &dp){
        // Base case
        if(n==0) return first == second ? first : 0;

        int key = first - second;
        if(dp.find({n, key}) != dp.end()) return dp[{n, key}];

        // Recursive case
        int includeFirst = equalSum(arr, n-1, first+arr[n-1], second, dp);
        int includeSecond = equalSum(arr, n-1, first, second+arr[n-1], dp);
        int exclude = equalSum(arr, n-1, first, second, dp);

        return dp[{n, key}] = max({includeFirst, includeSecond, exclude});
    }
    int tallestBillboard(vector<int>& rods) {
        int sum = 0;
        int n = rods.size();
        for(int i=0; i<n; i++) sum += rods[i];
        // int ans = 0;
        // for(int i=sum/2; i>=0; i--){
        //     vector<int> vis(n, 0);
        //     if(isExist(rods, n, i, vis) && isExist(rods, n, i, vis)){
        //         return i;
        //     }
        // }
        // return ans;
        map<pair<int, int>, int> dp;
        return equalSum(rods, n, 0, 0, dp);
    }
};


int main(){
    Solution s;
    vector<int> rods = {112,101,104,93,106,81};
    int target = 503;
    vector<int> vis(rods.size(), 0);
    cout<<s.isExist(rods, rods.size(), target, vis)<<endl;
    // Elements that made the sum
    for(int i=0; i<rods.size(); i++){
        if(vis[i] == 1) cout<<rods[i]<<" ";
    }
    cout<<endl;
    return 0;
}