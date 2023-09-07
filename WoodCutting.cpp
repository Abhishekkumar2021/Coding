#include<bits/stdc++.h>
using namespace std;

bool possible(int h, int sum, vector<int>&height){
    int total = 0, n = height.size();
    for(int i=0; i<n; i++){
        total += max(0, height[i] - h);
        if(total >= sum) return true;
    }
    return false;
}

int solve(vector<int> &A, int B) {
    int left = 0, right = *max_element(A.begin(), A.end());
    int ans = 0;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(possible(mid, B, A)){
            left = mid + 1;
            ans = mid;
        }else{
            right = mid - 1;
        }
    }
    return ans;
}