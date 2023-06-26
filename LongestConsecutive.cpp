#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    // First method: Using map
    // unordered_map<int, int> mp;
    // sort(nums.begin(), nums.end());
    // int ans = 0;
    // int n = nums.size();
    // for(int i=0; i<n; i++){
    //     if(mp.find(nums[i]-1) != mp.end()){
    //         mp[nums[i]] = mp[nums[i]-1] + 1;
    //     }
    //     else{
    //         mp[nums[i]] = 1;
    //     }
    //     ans = max(ans, mp[nums[i]]);
    // }
    // return ans;

    // Second method: Using set
    unordered_set<int> s(nums.begin(), nums.end());
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        if(s.find(nums[i]-1) == s.end()){
            // We have found the starting point of the sequence
            int curr = 1;
            int j = nums[i] + 1;
            while(s.find(j) != s.end()){
                curr++;
                j++;
            }
            ans = max(ans, curr);
        }
    }

    return ans;

}