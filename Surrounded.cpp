#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col){
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != 'O')
            return;
        board[row][col] = '1';
        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<m; i++) {
            if(board[0][i] == 'O') dfs(board, 0, i);
            if(board[n-1][i] == 'O') dfs(board, n-1, i);
        }

        for(int i=0; i<n; i++) {
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][m-1] == 'O') dfs(board, i, m-1);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == '1') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};