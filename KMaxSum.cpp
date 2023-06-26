#include <bits/stdc++.h> 
using namespace std;

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    vector<int> ans;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> s;
    pq.push({a[n-1]+b[n-1],{n-1,n-1}});
    s.insert({n-1,n-1});
    while(k--){
        pair<int,pair<int,int>> p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        int i = p.second.first;
        int j = p.second.second;
        if(s.find({i-1,j})==s.end()){
            pq.push({a[i-1]+b[j],{i-1,j}});
            s.insert({i-1,j});
        }
        if(s.find({i,j-1})==s.end()){
            pq.push({a[i]+b[j-1],{i,j-1}});
            s.insert({i,j-1});
        }
    }
    return ans;
}