#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int target){
    int n = arr.size();
    vector<int> ans;
    int sum = 0;
    int left = 0, right = 0;
    while(right < n){
        sum += arr[right];
        while(sum > target){
            sum -= arr[left];
            left++;
        }
        if(sum == target){
            ans.push_back(left+1);
            ans.push_back(right+1);
            return ans;
        }
        right++;
    }
    return ans;
}