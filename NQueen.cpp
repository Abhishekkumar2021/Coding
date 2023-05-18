#include<bits/stdc++.h>
using namespace std;

bool isOk(vector<int> &sol, int row, int col){
    // Function to check that if it is possible to place the queen at (i, j) position, where sol contains all the columns of the queens placed till now with their row number as the index.
    for(int i=0; i<row; i++){
        if(sol[i] == col || abs(i-row) == abs(sol[i]-col)){
            return false;
        }
    }
    return true;
}

void place(int row, int n, vector<vector<int>> &ans, vector<int> &sol){
    if(row == n){
        vector<int> temp(n*n, 0);
        for(int i=0; i<n; i++){
            temp[i*n + sol[i]] = 1;
        }
        ans.push_back(temp);
    }

    for(int col=0; col<n; col++){
        if(isOk(sol, row, col)){
            sol[row] = col;
            place(row+1, n, ans, sol);
            sol[row] = -1;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> sol(n, -1);
    place(0, n, ans, sol);
    return ans;
}