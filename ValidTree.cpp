#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> adjlist, int pr, int cn, vector<bool> &vst)
{
    if (vst[cn])
        return false;
    vst[cn] = true;
    int cc = adjlist[cn].size();
    for (int i = 0; i < cc; i++)
    {
        if (adjlist[cn][i] != pr)
        {
            if (!dfs(adjlist, cn, adjlist[cn][i], vst))
                return false;
        }
    }
    return true;
}
bool checkgraph(vector<vector<int>> edges, int n, int m)
{
    vector<vector<int>> adjlist(n);
    vector<bool> vst(n, false);
    for (int i = 0; i < m; i++)
    {
        adjlist[edges[i][0]].push_back(edges[i][1]);
        adjlist[edges[i][1]].push_back(edges[i][0]);
    }
    if (!dfs(adjlist, -1, 0, vst))
        return false;
    for (int i = 0; i < n; i++)
    {
        if (!vst[i])
            return false;
    }
    return true;
}