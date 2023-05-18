#include <bits/stdc++.h> 
using namespace std;

int sum(vector<int> adj[], int n, int src){
    vector<int> dis(n, 0);
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    dis[src] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i=0; i<adj[node].size(); i++){
            int child = adj[node][i];
            if(!visited[child]){
                visited[child] = true;
                dis[child] = dis[node] + 1;
                q.push(child);
            }
        }
    }

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += dis[i];
    }

    return sum;
    
}
vector<int> sumofDistance_Naive(vector<vector<int>> &edges, int n) // O(N^2)
{
    // Write your code here.
    

    vector<int> adj[n];
    for(int i=0; i<edges.size(); i++){
        int src = edges[i][0];
        int des = edges[i][1];
        adj[src].push_back(des);
        adj[des].push_back(src);
        
    }

    vector<int> ans(n, 0);
    for(int i=0; i<n; i++){
        ans[i] = sum(adj, n, i);
    }



    return ans;

}

// Effecient Solution
void dfs(vector<int> adj[], int n, int src, vector<int> &count, vector<int> &dis, vector<bool> &visited){
    visited[src] = true;
    for(int i=0; i<adj[src].size(); i++){
        int child = adj[src][i];
        if(!visited[child]){
            dfs(adj, n, child, count, dis, visited);
            count[src] += count[child];
            dis[src] += dis[child] + count[child];
        }
    }
    count[src]++;
}

void dfs2(vector<int> adj[], int n, int src, vector<int> &count, vector<int> &dis, vector<bool> &visited){
    visited[src] = true;
    for(int i=0; i<adj[src].size(); i++){
        int child = adj[src][i];
        if(!visited[child]){
            dis[child] = dis[src] - count[child] + n - count[child];
            dfs2(adj, n, child, count, dis, visited);
        }
    }
}




int main(){
    int n;
    cin>>n;
    vector<vector<int>> edges;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin>>u>>v;
        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);
        edges.push_back(temp);
    }

    vector<int> ans = sumofDistance(edges, n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

