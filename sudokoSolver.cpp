#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char c){
	for(int i = 0; i < 9; i++) if(board[row][i] == c || board[i][col] == c) return false;
	int x = row / 3 * 3, y = col / 3 * 3;
	for(int i = x; i < x + 3; i++){
		for(int j = y; j < y + 3; j++){
			if(board[i][j] == c) return false;
		}
	}
	return true;
}

bool solver(vector<vector<char>>& board, int row, int col){
	if(row == 9){
		return true;
	}
	if(col == 9){
		return solver(board, row + 1, 0);
	}
	if(board[row][col] != '.'){
		return solver(board, row, col + 1);
	}
	for(int i = 1; i <= 9; i++){
		char c = i + '0';
		if(isValid(board, row, col, c)){
			board[row][col] = c;
			if(solver(board, row, col + 1)){
				return true;
			}
			board[row][col] = '.';
		}
	}
	return false;
}

void solveSudoku(vector<vector<char>>& board) {
	solver(board, 0, 0);
}