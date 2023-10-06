#include<bits/stdc++.h>
using namespace std;

class point{
    public:
    int x;
    int y;
    point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

bool possible(int mid, vector<vector<int>> &dist, vector<vector<bool>> &vis, point p){
    int n = dist.size();
    if(vis[p.x][p.y]) return false;
    if(p.x == n-1 && p.y == n-1) return true;
    
    vis[p.x][p.y] = true;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for(int k=0; k<4; k++){
        int newX = p.x + dx[k];
        int newY = p.y + dy[k];
        if(newX >=0 && newX < n && newY >= 0 && newY < n && dist[newX][newY] >= mid){
            if(possible(mid, dist, vis, point(newX, newY))) return true;
        }
    }
    vis[p.x][p.y] = true;
    return false;
    
}

int maximumSafenessFactor(vector<vector<int>>& grid) {
    queue<point> q;
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n , INT_MAX));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1){
                q.push(point(i, j));
                dist[i][j] = 0;
            } 
        }
    }
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    while(!q.empty()){
        point p = q.front();
        q.pop();
        for(int k=0; k<4; k++){
            int newX = p.x + dx[k];
            int newY = p.y + dy[k];
            if(newX >=0 && newX < n && newY >= 0 && newY < n && dist[newX][newY] > dist[p.x][p.y] + 1){
                dist[newX][newY] = dist[p.x][p.y] + 1;
                q.push(point(newX, newY));
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    int left = 0, right = n;
    int ans = -1;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    while(left <= right){
        int mid = left + (right-left)/2;
        cout << left << " " << right << "\n";
        if(dist[0][0] >= mid && possible(mid, dist, vis, point(0, 0))){
            ans = mid;
            left = mid + 1;
        }else right = mid - 1;
    }

    return ans;

}

int main(){
    vector<vector<int>> grid = {{0,1, 1},{0,0,0},{0,0,0}};
    maximumSafenessFactor(grid);
}