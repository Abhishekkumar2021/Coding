#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, pair<int, int>>> pq;
        int n = a.size(), m = b.size();
        for(int i = 0; i < n; i++) {
            pq.push({-(a[i] + b[0]), {i, 0}});
        }

        while(k-- && !pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int i = p.second.first, j = p.second.second;
            ans.push_back({a[i], b[j]});
            if(j + 1 < m) {
                pq.push({-(a[i] + b[j + 1]), {i, j + 1}});
            }
        }

        return ans;
    }
};