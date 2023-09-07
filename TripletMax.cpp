#include<bits/stdc++.h>
using namespace std;

/*
Given an array A containing N integers.

You need to find the maximum sum of triplet ( Ai + Aj + Ak ) such that 0 <= i < j < k < N and Ai < Aj < Ak.

If no such triplet exist return 0.
*/
int maxSum(vector<int> &arr){
    int n = arr.size();
    int maxSum = 0;
    vector<int> suffixMax(n, 0);
    suffixMax[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        suffixMax[i] = max(suffixMax[i+1], arr[i]);
    }
    set<int> s;
    s.insert(arr[0]);
    for(int i = 1; i < n-1; i++){
        if(suffixMax[i+1] > arr[i]){
            auto it = s.lower_bound(arr[i]);
            if(it != s.begin()){
                it--;
                maxSum = max(maxSum, *it + arr[i] + suffixMax[i+1]);
            }
        }
        s.insert(arr[i]);
    }
    return maxSum;
    
}