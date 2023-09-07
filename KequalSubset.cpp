#include<bits/stdc++.h>
using namespace std;

bool partition(vector<int>& nums, int n, vector<int> &sum, map<string, int> &dp){
    if(n==0){
        // Check if all elements are equal or not?
        int min = *min_element(sum.begin(), sum.end());
        int max = *max_element(sum.begin(), sum.end());
        return min == max;
    }

    string key = "";
    for(auto &s: sum){
        key += to_string(s);
    }

    if(dp.find(key) != dp.end()) return dp[key];

    // Try to put the current element in everyone
    int k = sum.size();
    for(int i=0; i<k; i++){
        sum[i] += nums[n-1];
        if(partition(nums, n-1, sum, dp)) return dp[key] = true;
        sum[i] -= nums[n-1];
    }
    return dp[key] = false;
}

bool partition(vector<int> &nums, int k, int curr, int target, int mask, map<string, bool> &dp){
    // base cases
    if(k==1) return true;
    if(curr == target) return partition(nums, k-1, 0, target, mask, dp);
    string key = to_string(k) + "$" + to_string(curr) + "$" + to_string(mask);
    if(dp.find(key) != dp.end()) return dp[key];
    int n = nums.size();
    int idx = 0;
    while(idx < n){
        if((mask & (1<<idx)) == 0){
            int temp = nums[idx];
            curr += temp;
            if(partition(nums, k, curr, target, mask | (1<<idx), dp)) return dp[key] = true;
            curr -= temp;
            while(nums[idx] == temp) idx++;
        }
        else idx++;
    }
    return dp[key] = false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % k != 0) return false;
    int mask = 0;
    map<string, bool> dp;
    sort(nums.begin(), nums.end());
    return partition(nums, k, 0, sum/k, mask, dp);
}