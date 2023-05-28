#include <bits/stdc++.h>
using namespace std;

// int MinimumEffort(vector<vector<int>> &heights)
// {
//     int rows = heights.size();
//     int cols = heights[0].size();
//     vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
//     dist[0][0] = 0;
//     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
//     pq.push(make_pair(0, make_pair(0, 0)));
//     vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//     while (!pq.empty()) {
//         pair<int, pair<int, int>> top = pq.top();
//         pq.pop();
//         int effort = top.first;
//         int row = top.second.first;
//         int col = top.second.second;
//         if (row == rows-1 && col == cols-1) {
//             return effort;
//         }
//         for (auto dir : dirs) {
//             int nr = row + dir.first;
//             int nc = col + dir.second;
//             if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
//                 continue;
//             }
//             int new_effort = max(effort, abs(heights[row][col] - heights[nr][nc]));
//             if (new_effort < dist[nr][nc]) {
//                 dist[nr][nc] = new_effort;
//                 pq.push(make_pair(new_effort, make_pair(nr, nc)));
//             }
//         }
//     }
//     return -1;
// }

void ins(int i, int j, int p1, int p2, vector<vector<int>> &height, vector<vector<int>> &dis, priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> &q, int effort)
{
    if (i >= height.size() || j >= height[0].size() || i < 0 || j < 0)
        return;
    int height_diff = abs(height[i][j] - height[p1][p2]);
    int new_effort = max(effort, height_diff);
    if (dis[i][j] > new_effort)
    {
        dis[i][j] = new_effort;
        q.push({dis[i][j], {i, j}});
    }
    return;
}
int MinimumEffort(vector<vector<int>> &height)
{
    int n = height.size();
    int m = height[0].size();
    vector<vector<int>> dis(n, vector<int>(m, 1e9));
    dis[0][0] = 0;
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        q;
    q.push({0, {0, 0}});
    while (q.size() != 0)
    {
        int i = q.top().second.first;
        int j = q.top().second.second;
        int di = q.top().first;

        if(i==n-1 && j==m-1)
            return di;

        ins(i, j + 1, i, j, height, dis, q, di);
        ins(i, j - 1, i, j, height, dis, q, di);
        ins(i + 1, j, i, j, height, dis, q, di);
        ins(i - 1, j, i, j, height, dis, q, di);
        q.pop();
    }
    return 0;
}