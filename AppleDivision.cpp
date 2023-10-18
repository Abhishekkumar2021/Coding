#include <bits/stdc++.h>
using namespace std;
void rec(int idx, vector<int> &weight, long long cur_sum, long long &res, long long &t_sum, int &n)
{
    if (idx == n)
    {
        res = min(res, abs(2 * cur_sum - t_sum));
        return;
    }
    int i;
    rec(idx + 1, weight, cur_sum, res, t_sum, n);
    rec(idx + 1, weight, cur_sum + weight[idx], res, t_sum, n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> weight(n);
    int i;
    long long res = LLONG_MAX, t_sum = 0;
    for (i = 0; i < n; i++)
    {
        cin >> weight[i];
        t_sum += weight[i];
    }
    rec(0, weight, 0, res, t_sum, n);
    cout << res << "\n";
    return 0;
}
