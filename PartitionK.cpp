#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkSubset(vector<int> &arr, int n, int sum, vector<bool> &visited){
    if(sum==0) return true;
    if(n==0) return false;

    if(visited[n-1]) return checkSubset(arr, n-1, sum, visited);

    if(arr[n-1] <= sum){
        visited[n-1] = true;
        if(checkSubset(arr, n-1, sum-arr[n-1], visited)) return true;
        visited[n-1] = false;
    }
    return checkSubset(arr, n-1, sum, visited);
}

bool splitArray(vector<int>& nums, int k) {
    vector<bool> visited(nums.size(), false);
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
    }
    if(sum%k != 0) return false;
    sum = sum/k;
    for(int i=0; i<k; i++){
        if(!checkSubset(nums, nums.size(), sum, visited)) return false;
    }
}


