#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    if(numRows==0) return ans;
    for(int i=0; i<numRows; i++){
        vector<int> temp = {1};
        int cols = i+1;
        for(int j=1; j<cols; j++){
            if(j==cols-1) temp.push_back(1);
            else temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
        }
        ans.push_back(temp);
    }
    return ans;
}