#include<bits/stdc++.h>
using namespace std;

vector<int> manacher(string &t)
{
    string s = "#";
    for (int i = 0; i < t.size(); i++)
    {
        s.push_back(t[i]);
        s.push_back('#');
    }
    
    int n = s.size();
    vector<int> dp(n, 1);
    int cur = 1;
    while (cur < n)
    {
        int i = cur - dp[cur] / 2 - 1, j = cur + dp[cur] / 2 + 1;
        while (i >= 0 && j < n && s[i] == s[j])
        {
            i--, j++;
        }
        dp[cur] = j - i - 1;
        // finding next cur
        int nxt = j;
        for (int k = cur + 1; k < j; k++)
        {
            int mir = dp[2 * cur - k];
            dp[k] = min(mir, (j - k) * 2 - 1);
            if (k + mir / 2 == j - 1)
            {
                nxt = k;
                dp[nxt] = mir;
                break;
            }
        }
        cur = nxt;
    }
    return dp;
}


int solve(string A) {
    int n = A.size();
    vector<int> dp = manacher(A);
    int len = 0;
    for(int i=0; i< dp.size(); i++){
        int l = i - dp[i]/2;
        if(l == 0) len = max(len, dp[i]/2);
    }
    return n - len;
}

int main(){
    solve("abac");
}