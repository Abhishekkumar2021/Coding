#include<bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> pre(n, 1);
    for(int i=1; i<n; i++) {
        pre[i] = pre[i-1] * nums[i-1];
    }
    vector<int> ans(n);
    int right = 1;
    for(int i=n-1; i>=0; i--) {
        ans[i] = pre[i] * right;
        right *= nums[i];
    }
    return ans;
}