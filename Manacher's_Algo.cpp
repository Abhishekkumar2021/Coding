#include<bits/stdc++.h>
using namespace std;

string LongestpalindromicSubstring(string &s){
    string str = "#";
    for(auto &c : s){
        str += c;
        str += "#";
    }
    int n = str.size();
    vector<int> P(n, 0);
    int C = 0, R = 0;
    for(int i = 1; i < n - 1; i++){
        int mirror = 2 * C - i;
        if(i < R){
            P[i] = min(R - i, P[mirror]);
        }
        while(str[i + (1 + P[i])] == str[i - (1 + P[i])]){
            P[i]++;
        }
        if(i + P[i] > R){
            C = i;
            R = i + P[i];
        }
    }
    int maxLen = 0, centerIndex = 0;
    for(int i = 1; i < n - 1; i++){
        if(P[i] > maxLen){
            maxLen = P[i];
            centerIndex = i;
        }
    }
    string ans = "";
    for(int i = centerIndex - maxLen; i <= centerIndex + maxLen; i++){
        if(str[i] != '#'){
            ans += str[i];
        }
    }
    return ans;
}