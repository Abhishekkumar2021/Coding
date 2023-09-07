#include<bits/stdc++.h>
using namespace std;

int highestScore(vector<vector<string> > &A) {
    // {name, {avg, count}}
    map<string, pair<float, int>> m;
    for(auto &x: A){
        if(m.find(x[0]) == m.end()) m[x[0]]= {stof(x[1]), 1};
        else{
            float currAvg = m[x[0]].first;
            int currCount = m[x[0]].second;
            m[x[0]] = {(currAvg*currCount + stof(x[1]))/(currCount+1), currCount+1};
        }
    }
    float ans = 0;
    for(auto &p: m) ans = max(ans, p.second.first);
    return ans;
}