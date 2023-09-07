#include<bits/stdc++.h>
using namespace std;

int countWays(vector<int> &arr){
    int n = arr.size();
    int sum = 0;
    for(auto &x: arr) sum += x;
    if(sum%3 != 0) return 0;
    
    int required = sum/3;
    int curr = 0;
    int count = 0;
    int ans = 0;
    for(int i=0; i<n-1; i++){
        curr += arr[i];
        if(curr == 2*required){
            ans += count;
        }
        if(curr == required){
            count++;
        }
    }

    return ans;
}