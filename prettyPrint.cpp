#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> prettyPrint(int n) {
    int size = 2*n-1;
    vector<vector<int>> ans(size, vector<int>(size));
    int depth = 0;
    while(depth < n){
        for(int i=depth; i<size-depth; i++) ans[depth][i] = n - depth;
        for(int i=depth; i<size-depth; i++) ans[size-depth-1][i] = n - depth;
        for(int i=depth; i<size-depth; i++) ans[i][depth] = n - depth;
        for(int i=depth; i<size-depth; i++) ans[i][size-depth-1] = n - depth;
        depth++;
    }
    return ans;
}