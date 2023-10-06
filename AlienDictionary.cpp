// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<int> adj[k];
        vector<int> indegree(k, 0);
        for(int i=1; i<n; i++){
            string a = dict[i-1];
            string b = dict[i];
            for(int j=0; j<min(a.size(), b.size()); j++){
                if(a[j] != b[j]){
                    adj[a[j]-'a'].push_back(b[j]-'a');
                    indegree[b[j]-'a']++;
                    break;
                }
            }
        }
        
        string ans = "";
        queue<int> q;
        for(int i=0; i<k; i++) if(indegree[i]==0) q.push(i);
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            ans.push_back(x + 'a');
            for(auto &child: adj[x]){
                indegree[child]--;
                if(indegree[child]==0) q.push(child);
            }
        }
        return ans;
    }
};