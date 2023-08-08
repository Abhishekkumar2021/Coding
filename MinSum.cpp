#include<bits/stdc++.h>
using namespace std;


/*
Given an array A consisting of N non-negative integers your task is to find the minimum sum of the array such that out of 3 consecutive  elements you need to add at-least one.
*/

int sum(int arr[], int n, vector<int> &dp){
    // base case
    if(n<=0) return 0;

    // memoization
    if(dp[n] != -1) return dp[n];

    return dp[n] = arr[n-1] + min({sum(arr, n-1, dp), sum(arr, n-2, dp), sum(arr, n-3, dp)});
}