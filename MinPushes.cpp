#include<bits/stdc++.h>
using namespace std;



int minPushes(int m, int n, vector<vector<char>> &grid) {
    // Write your code here.
    int srcX, srcY, destX, destY, playerX, playerY;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 'S'){
                playerX = i;
                playerY = j;
            }
            if(grid[i][j] == 'B'){
                srcX = i;
                srcY = j;
            }
            if(grid[i][j] == 'T'){
                destX = i;
                destY = j;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({srcX, srcY});
    vector<vector<int>> visited(m, vector<int>(n, 0));
    visited[srcX][srcY] = 1;
    int ans = 0;
    // . represents empty space
    // | represents wall
    // S represents player

    while(!q.empty()){
        int size = q.size();
        while(size--){
            pair<int, int> curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            if(x == destX && y == destY){
                return ans;
            }
            if(x+1 < m && visited[x+1][y] == 0 && grid[x+1][y] != '|'){
                visited[x+1][y] = 1;
                q.push({x+1, y});
            }
            if(x-1 >= 0 && visited[x-1][y] == 0 && grid[x-1][y] != '|'){
                visited[x-1][y] = 1;
                q.push({x-1, y});
            }
            if(y+1 < n && visited[x][y+1] == 0 && grid[x][y+1] != '|'){
                visited[x][y+1] = 1;
                q.push({x, y+1});
            }
            if(y-1 >= 0 && visited[x][y-1] == 0 && grid[x][y-1] != '|'){
                visited[x][y-1] = 1;
                q.push({x, y-1});
            }
        }
        ans++;
    }
}