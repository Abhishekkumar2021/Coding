#include <bits/stdc++.h>
using namespace std;

/*
Thief cannot rob two adjacent houses.
Find the maximum amount of money thief can rob.

Approach:
1. We will use dynamic programming.
2. We will create a dp array of size n+1.
3. dp[i] will store the maximum amount of money thief can rob from 0 to i houses.
4. dp[0] = 0, dp[1] = arr[0].
5. dp[i] = max(dp[i-1], dp[i-2] + arr[i-1]).
*/

int maxMoneyLooted(vector<int> &arr, int n)
{
    /*
        Write your code here.
        Don't write main().
        Don't take input, it is passed as function argument.
        Don't print output.
        Taking input and printing output is handled automatically.
    */

    // Creating a dp array of size n+1.
    int dp[n + 1];

    // dp[0] = 0, dp[1] = arr[0].
    dp[0] = 0;
    dp[1] = arr[0];

    // dp[i] = max(dp[i-1], dp[i-2] + arr[i-1]).
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
    }

    // Returning the maximum amount of money thief can rob from 0 to n houses.
    return dp[n];
}