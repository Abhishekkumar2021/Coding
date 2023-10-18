#include <bits/stdc++.h>
using namespace std;

vector<int> dr = {0, 0, -1, 1};
vector<int> dc = {-1, 1, 0, 0};
vector<vector<bool>> vis(7, vector<bool>(7, false));
string s;

bool check(int i, int j)
{
    bool a = (j - 1 < 0 || vis[i][j - 1]);
    bool b = (j + 1 > 6 || vis[i][j + 1]);
    bool c = (i - 1 >= 0 && vis[i - 1][j] == 0);
    bool d = (i + 1 <= 6 && vis[i + 1][j] == 0);
    bool x = (a && b) && (c && d);

    bool p = (j - 1 >= 0 && vis[i][j - 1] == 0);
    bool q = (j + 1 <= 6 && vis[i][j + 1] == 0);
    bool r = (i - 1 < 0 || vis[i - 1][j]);
    bool s = (i + 1 > 6 || vis[i + 1][j]);
    bool y = (p && q) && (r && s);

    return x || y;
}

int ways(int idx, int i, int j)
{
    // if (check(i, j))
    // {
    //     return 0;
    // }

    bool a = (j - 1 < 0 || vis[i][j - 1]);
    bool b = (j + 1 > 6 || vis[i][j + 1]);
    bool c = (i - 1 >= 0 && vis[i - 1][j] == 0);
    bool d = (i + 1 <= 6 && vis[i + 1][j] == 0);
    bool x = (a && b) && (c && d);

    bool p = (j - 1 >= 0 && vis[i][j - 1] == 0);
    bool q = (j + 1 <= 6 && vis[i][j + 1] == 0);
    bool r = (i - 1 < 0 || vis[i - 1][j]);
    bool t = (i + 1 > 6 || vis[i + 1][j]);
    bool y = (p && q) && (r && t);

    if(x || y)return 0;

    if (idx == 48)
    {
        if (i == 6 && j == 0)
            return 1;
        return 0;
    }
    if (i == 6 && j == 0)
        return 0;

    vis[i][j] = true;
    int ans = 0;
    if (s[idx] == '?')
    {
        for (int k = 0; k < 4; k++)
        {
            int newR = i + dr[k];
            int newC = j + dc[k];
            if (newR < 0 || newR >= 7 || newC < 0 || newC >= 7 || vis[newR][newC])
                continue;
            ans += ways(idx + 1, newR, newC);
        }
    }
    else if (s[idx] == 'U' && i - 1 >= 0 && !vis[i - 1][j])
    {
        ans += ways(idx + 1, i - 1, j);
    }
    else if (s[idx] == 'D' && i + 1 <= 6 && !vis[i + 1][j])
    {
        ans += ways(idx + 1, i + 1, j);
    }
    else if (s[idx] == 'L' && j - 1 >= 0 && !vis[i][j - 1])
    {
        ans += ways(idx + 1, i, j - 1);
    }
    else if (s[idx] == 'R' && j + 1 <= 6 && !vis[i][j + 1])
    {
        ans += ways(idx + 1, i, j + 1);
    }
    vis[i][j] = false;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    cout << ways(0, 0, 0) << "\n";
    return 0;
}
