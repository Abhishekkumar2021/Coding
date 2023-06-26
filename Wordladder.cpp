#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string src, string des, vector<string>& wordList) {
        int ans = 0;
        int n = src.size();
        queue<pair<string, int>> q;
        unordered_set<string> s(wordList.begin(), wordList.end());
        q.push({src, 1});
        s.erase(src);
        while(!q.empty()){
            pair<string, int> p = q.front();
            q.pop();
            string str = p.first;
            int len = p.second;
            if(str == des){
                ans = len;
                break;
            }
            for(int i = 0; i < n; i++){
                char ch = str[i];
                for(int j = 0; j < 26; j++){
                    str[i] = 'a' + j;
                    if(s.find(str) != s.end()){
                        q.push({str, len + 1});
                        s.erase(str);
                    }
                }
                str[i] = ch;
            }
        }
        return ans;
    }
};