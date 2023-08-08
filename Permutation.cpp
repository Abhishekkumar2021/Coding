#include<bits/stdc++.h>
using namespace std;

void permute(string &s, int idx, int n, vector<string> &ans)
{
    if (idx == n)
    {
        ans.push_back(s);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        swap(s[i], s[idx]);
        permute(s, idx + 1, n, ans);
        swap(s[i], s[idx]);
    }
}

void permute2(string &s, vector<bool> &vis, string &temp, vector<string> &ans)
{
    if (temp.size() == s.size())
    {
        ans.push_back(temp);
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (vis[i] == false)
        {
            vis[i] = true;
            temp.push_back(s[i]);
            permute2(s, vis, temp, ans);
            temp.pop_back();
            vis[i] = false;
        }
    }
}