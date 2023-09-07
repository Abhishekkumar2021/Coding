#include<bits/stdc++.h>
using namespace std;

int maxCherry(vector<vector<int>> &grid, int row1, int row2, int col1, int n, vector<vector<vector<int>>> &dp){
    int col2 = row1 + col1 - row2;
    // base cases
    if(row1 == n-1 && col1 == n-1) return grid[row1][col1];  // Checking reachability of one is fine as other one is moving similarly
    if(row1 >= n || row2 >= n || col1 >= n || col2 >= n || grid[row1][col1] == -1 || grid[row2][col2] == -1) return -1e7;
    if(dp[row1][row2][col1] != -1) return dp[row1][row2][col1];
    int ans = 0;
    if(row1 == row2 && col1 == col2) ans += grid[row1][col1];
    else ans += grid[row1][col1] + grid[row2][col2];

    // RR, RD, DR, DD
    int RR = maxCherry(grid, row1, row2, col1 + 1, n, dp);
    int RD = maxCherry(grid, row1, row2+1, col1 + 1,  n, dp);
    int DR = maxCherry(grid, row1+1, row2, col1,  n, dp);
    int DD = maxCherry(grid, row1+1, row2+1, col1, n, dp);
    return dp[row1][row2][col1]= ans + max({RR, RD, DR, DD});
}
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    const int INF = 1e7;
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, -INF)));
    // return max(0, maxCherry(grid, 0, 0, 0, n, dp));
    
}