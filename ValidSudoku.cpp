#include<bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == '.') continue;
            for(int k=0; k<9; k++){
                if(k!=j && board[i][j] == board[i][k]) return false;
                if(k!=i && board[i][j] == board[k][j]) return false;
            }
            for(int k=0; k<3; k++){
                for(int l=0; l<3; l++){
                    int x = i/3*3 + k;
                    int y = j/3*3 + l;
                    if(x!=i && y!=j && board[i][j] == board[x][y]) return false;
                }
            }

        }
    }
    return true;
}