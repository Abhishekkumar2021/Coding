#include<bits/stdc++.h>
using namespace std;

string commonChar(vector<string> &s){
    string ans = "";
    int n = s.size();
    int count[26];
    memset(count, 0, sizeof(count));
    for(int i=0; i<n; i++){
        int temp[26] = {0};
        for(int j=0; j<s[i].length(); j++){
            temp[s[i][j]-'a']++;
        }
        for(int j=0; j<26; j++){
            count[j] = min(count[j], temp[j]);
        }
    }
}