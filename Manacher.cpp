#include <bits/stdc++.h>
using namespace std;

int manacher(string &t)
{
    // longest odd length palindrome length
    string s = "";
    for (int i = 0; i < t.size(); i++)
    {
        s.push_back('*');
        s.push_back(t[i]);
    }
    s.push_back('*');
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
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
    return *max_element(dp.begin(), dp.end()) / 2;
}

int main()
{
    string s;
    cin >> s;
    cout << manacher(s) << endl;
    return 0;
}