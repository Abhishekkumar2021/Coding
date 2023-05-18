#include<bits/stdc++.h>
using namespace std;

int *getProductArrayExceptSelf(int *arr, int n){
    int *ans = new int[n];
    long long *left = new long long[n];
    long long *right = new long long[n];
    left[0] = 1;
    right[n-1] = 1;
    for(int i=1; i<n; i++){
        left[i] = left[i-1]*arr[i-1];
    }
    for(int i=n-2; i>=0; i--){
        right[i] = right[i+1]*arr[i+1];
    }
    for(int i=0; i<n; i++){
        ans[i] = (int)left[i]*right[i];
    }
    return ans;
}