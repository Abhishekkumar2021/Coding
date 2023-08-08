/*
You are given a string s, you have to find out the index of its permutation in the sorted list of all permutations of the string s.
*/
#include<bits/stdc++.h>
using namespace std;

int getPermutaionIndex(string s){
    int n = s.length();
    vector<int> fact(n+1, 1);
    for(int i = 1; i <= n; i++){
        fact[i] = fact[i-1] * i;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = i+1; j < n; j++){
            if(s[j] < s[i]){
                count++;
            }
        }
        ans += count * fact[n-i-1];
    }
    return ans + 1;
}