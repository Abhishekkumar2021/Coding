/*
You are given an array, and a number k, Check whether there exists duplicates in the array within the distance of k.
*/

#include <bits/stdc++.h>
using namespace std;

bool checkDuplicate(vector<int> &arr, int n, int k)
{
    // Write your code here.
    // unordered_map<int, int> mp;
    // for(int i = 0; i < n; i++) {
    //     if(mp.find(arr[i]) != mp.end()) {
    //         if(i - mp[arr[i]] <= k) {
    //             return true;
    //         }
    //     }
    //     mp[arr[i]] = i;
    // }
    // return false;

    // Method 2
    unordered_set<int> s;
    int mini = min(n, k);
    if(mini == n) {
        for(int i = 0; i < n; i++) {
            if(s.find(arr[i]) != s.end()) {
                return true;
            }
            else {
                s.insert(arr[i]);
            }
        }
        return false;
    }
    else{
        for(int i = 0; i < mini; i++) {
            if(s.find(arr[i]) != s.end()) {
                return true;
            }
            else {
                s.insert(arr[i]);
            }
        }
        for(int i = mini; i < n; i++) {
            if(s.find(arr[i]) != s.end()) {
                return true;
            }
            else {
                s.erase(arr[i - mini]);
                s.insert(arr[i]);
            }
        }
    }
    return false;
}