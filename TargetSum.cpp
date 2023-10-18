#include <bits/stdc++.h>
using namespace std;

int targetSum(int n, int target, vector<int> &arr)
{
    // Write your code here.
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    if ((sum + target) % 2 == 1)
        return 0;
    sum = (sum + target) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    sort(arr.rbegin(), arr.rend());
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, diff;
        cin >> n >> diff;
        vector<int> arr(n);
        for(auto &x: arr) cin >> x;
        cout << targetSum(n, diff, arr) << "\n";
    }
}