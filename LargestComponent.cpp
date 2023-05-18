/*
Problem Statement
You are given an array of positive integers, 'VERTICES' that represent the vertices in a
graph. Two vertices, 'VI' and 'V2t, have an edge between them if and only if 'Vlt and
'V2' share a common factor greater than 1. Your task is to return the size of the largest
connected component in the graph.

Sample Input 1:
2
6
8 10 13 15 6 28
9
4 25 7 14 27 23 17 34 3
Sample Output 1:
5
5
*/

#include<bits/stdc++.h>
using namespace std;

// int gcd(int a, int b){
//     if(b == 0){
//         return a;
//     }
//     return gcd(b, a%b);
// }

// void dfs(vector<int> adj[], int s, bool visited[], int &cnt){
//     visited[s] = true;
//     cnt++;
//     for(int i = 0; i < adj[s].size(); i++){
//         if(!visited[adj[s][i]]){
//             dfs(adj, adj[s][i], visited, cnt);
//         }
//     }
// }

// int largestComponentSize(vector<int> &arr, int n){
//     vector<int> adj[n+1];
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             if(gcd(arr[i], arr[j]) > 1){
//                 adj[i].push_back(j);
//                 adj[j].push_back(i);
//             }
//         }
//     }
//     int ans = INT_MIN;
//     bool visited[n+1];
//     memset(visited, false, sizeof(visited));
//     for(int i=0; i<n; i++){
//         if(!visited[i]){
//             int cnt = 0;
//             dfs(adj, i, visited, cnt);
//             ans = max(ans, cnt);
//         }
//     }
//     return ans;
// }