#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &cost, int idx)
    {
        if (idx >= cost.size())
            return 0;
        if (idx < 0)
        {
            int m = solve(cost, 0);
            int n = solve(cost, 1);
            return min(m, n);
        }
        int m = solve(cost, idx + 1) + cost[idx];
        int n = solve(cost, idx + 2) + cost[idx];
        return min(m, n);
    }
    int minCostClimbingStairs(vector<int> &cost)
    {
        return solve(cost, -1);
    }
};

int main(){
    Solution s;
    vector<int> cost = {10, 15, 20};
    cout << s.minCostClimbingStairs(cost);
}