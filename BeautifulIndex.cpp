#include<bits/stdc++.h>
using namespace std;

int beautifulIndex(int n, vector<int> arr)
{
	// Write your code here.
    vector<int> pre(n + 1, 0), suf(n + 2, 0);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + arr[i - 1];
    for (int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + arr[i - 1];

    for (int i = 1; i <= n; i++)
    {
        if (pre[i - 1] == suf[i + 1])
            return i;
    }
    return -1;
}