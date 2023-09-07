#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s){
    int i = 0, j = s.size() - 1;
    while(i<j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words){
    vector<vector<int>> ans;
    int n = words.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            if(palindrome(words[i] + words[j])) ans.push_back({i, j});
        }
    }
    return ans;
}