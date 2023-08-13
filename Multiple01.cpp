#include<bits/stdc++.h>
using namespace std;

string multiple(int n) {
    int num = 1;
    string ans = "";
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;
    q.push(num);
    visited[num] = true;
    while(!q.empty()){
        int num = q.front();
        q.pop();
        if(num == 0){
            while(num != -1){
                ans += to_string(num);
                num = parent[num];
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
        int rem = num%n;
        if(!visited[rem]){
            visited[rem] = true;
            parent[rem] = num;
            q.push(rem);
        }
        rem = (num*10)%n;
        if(!visited[rem]){
            visited[rem] = true;
            parent[rem] = num;
            q.push(rem);
        }
    }
}