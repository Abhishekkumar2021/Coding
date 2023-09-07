#include<bits/stdc++.h>
using namespace std;

int fun(int idx, string &s, int k, vector<int> &dp){
    const int mod = 1e9 + 7;
    int n = s.size();
    // If we have successfully reached to the end then this means we have got one array
    if(idx == n) return 1;
    // if string contains leading zero then this means that no array is possible like this
    if(s[idx] == '0') return 0;

    if(dp[idx] != -1) return dp[idx];

    int ans = 0;
    int i = idx; 
    while(i<n){
        string sub = s.substr(idx, i-idx+1);
        long num = stol(sub);
        if(num>k) break;
        ans = (ans + fun(i+1, s, k, dp))%mod;
        i++;
    }
    return dp[idx] = ans;
}

int numDigits(int k){
    int ans = 0;
    while(k>0){
        ans++;
        k /= 10;
    }
    return ans;
}

int tabulation(string &s, int k){
    const int mod = 1e9 + 7;
    int n = s.size();
    vector<int> dp(n+1, 1);
    for(int idx = n-1; idx >= 0; idx--){
        if(s[idx] == '0') dp[idx] = 0;
        else{
            int ans = 0;
            int i = idx;
            long num = 0; 
            while(i<n){
                num = num*10 + (s[i] - '0');
                if(num >= 1 && num <= k){
                    ans = (ans + dp[i+1])%mod;
                    i++;
                }else break;
            }
            dp[idx] = ans;
        }
    }
    return dp[0];
}

// returns the number of arrays possible 
int numberOfArrays(string s, int k) {
    return tabulation(s, k);
}
