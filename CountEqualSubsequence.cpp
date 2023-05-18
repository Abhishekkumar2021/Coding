#include<bits/stdc++.h>
using namespace std;

// Count all the subsequences of an array which have all the elements equal

long countSubsequences(int* arr, int n) {
    // Write your code here. 
    int mod = 1e9 + 7;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }
    long ans = 0;
    for(auto it = mp.begin(); it != mp.end(); it++) {
        ans = (ans + (long)pow(2, it->second) - 1) % mod;
    }
    return ans;

}