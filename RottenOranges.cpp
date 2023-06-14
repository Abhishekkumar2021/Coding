#include<bits/stdc++.h>
using namespace std;

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    int ans = -1;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    queue<pair<int, int>> q;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid[i][j] == 2)
                q.push({i, j});

    while(!q.empty())
    {
        int size = q.size();
        while(size--) // for each level
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
        ans++;
    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(grid[i][j] == 1)
                return -1;
    
    return ans;

    // Method 2
    // queue<vector<int>> q;
    // for(int i=0; i<n; i++)
    //     for(int j=0; j<m; j++)
    //         if(grid[i][j] == 2)
    //             q.push({i, j, 0});

    // while(!q.empty())
    // {
    //     int x = q.front()[0];
    //     int y = q.front()[1];
    //     int time = q.front()[2];
    //     q.pop();
    //     for(int i=0; i<4; i++)
    //     {
    //         int nx = x + dx[i];
    //         int ny = y + dy[i];
    //         if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
    //         {
    //             grid[nx][ny] = 2;
    //             q.push({nx, ny, time+1});
    //             ans = max(ans, time+1);
    //         }
    //     }
    // }

    // for(int i=0; i<n; i++)
    //     for(int j=0; j<m; j++)
    //         if(grid[i][j] == 1)
    //             return -1;

    // return ans == -1 ? 0 : ans;
}