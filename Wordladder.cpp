#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string src, string des, vector<string>& wordList) {
        int n = src.size();
        queue<string> q;
        unordered_set<string> s(wordList.begin(), wordList.end());
        q.push(src);
        int level = 1;
        s.erase(src);
        while(!q.empty()){
            int n = q.size();
            while(n--){ // Traversing level by level
                string curr = q.front();
                q.pop();
                if(curr == des){
                    return level;
                }
                for(int i=0; i<curr.size(); i++){
                    char temp = curr[i];
                    for(char c='a'; c<='z'; c++){
                        curr[i] = c;
                        if(s.find(curr) != s.end()){
                            q.push(curr);
                            s.erase(curr);
                        }
                    }
                    curr[i] = temp;
                }
            }
            level++;

        }
        return 0;
    }
};