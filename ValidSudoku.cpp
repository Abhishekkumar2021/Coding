#include<bits/stdc++.h>
using namespace std;

bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(matrix[i][j]==0)
            continue;

            // Row check
            for(int k=j+1; k<9; k++){
                if(matrix[i][j]==matrix[i][k])
                return false;
            }

            // Column check
            for(int k=i+1; k<9; k++){
                if(matrix[i][j]==matrix[k][j])
                return false;
            }

            // Subgrid check
            int subgridRow = i/3;
            int subgridCol = j/3;
            int x = subgridRow*3;
            int y = subgridCol*3;
            for(int k=x; k<x+3; k++){
                for(int l=y; l<y+3; l++){
                    if(k==i && l==j)
                    continue;
                    if(matrix[i][j]==matrix[k][l])
                    return false;
                }
            }
        }
    }

    return true;
} 