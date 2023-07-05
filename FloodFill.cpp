#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    vector<vector<int>> ans = image;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    int n = image.size(), m = image[0].size();
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        ans[x][y] = color;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && ans[nx][ny] != color && ans[nx][ny] == image[x][y]) {
                q.push({nx, ny});
                ans[nx][ny] = color;
            }
        }
    }
    return ans;
}