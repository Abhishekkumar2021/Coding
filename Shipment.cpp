#include<bits/stdc++.h>
using namespace std;

bool possible(int c, int days, vector<int> &arr){
    int cnt = 0;
    int sum = 0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum > c){
            sum = arr[i];
            cnt++;
        }

        if(cnt > days) return false;
    }
    return true;
}

int solve(vector<int> &A, int B) {
    int left = 0, right = INT_MAX;
    int ans = -1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(possible(mid, B, A)){
            ans = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return ans;
}