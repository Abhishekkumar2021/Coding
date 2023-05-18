/*
Given a matrix of size n x m, find the maximum sum of a rectangle in it. For example, consider the following matrix:

-1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6

The answer is 29, and the rectangle is: (1, 1) to (3, 3).

Hints: 
1. The naive solution is to try all possible rectangles and find the maximum sum. This solution is O(n^6).
2. Can we do better? Yes, we can. We can use Kadane's algorithm to find the maximum sum of a subarray in O(n^2) time. 
   So, we can find the maximum sum of a rectangle in O(n^4) time.
3. Can we do even better? Yes, we can. We can use the fact that the maximum sum of a rectangle is either the maximum sum of a 
   subarray or the maximum sum of a subarray with the left and right columns fixed. So, we can find the maximum sum of a 
   rectangle in O(n^3) time.

*/
#include<bits/stdc++.h>
using namespace std;

int maxSumNaive(vector<vector<int>> &a) {
    int n = a.size();
    int m = a[0].size();
    int ans = INT_MIN;
    // 4 nested loops to iterate over all possible rectangles (i, j) to (k, l) 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    // sum of the current rectangle
                    int sum = 0;
                    for (int x = i; x <= k; x++) {
                        for (int y = j; y <= l; y++) {
                            sum += a[x][y];
                        }
                    }
                    ans = max(ans, sum);
                }
            }
        }
    }
    return ans;
}

int maxSumKadane(vector<int> &a) {
    int n = a.size();
    int ans = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans = max(ans, sum);
        if (sum < 0) {
            sum = 0;
        }
    }
    return ans;
}

int maxSum(vector<vector<int>> &a) {
    int n = a.size();
    int m = a[0].size();
    int ans = INT_MIN;
    for(int start = 0; start < m; start++) {
        vector<int> temp(n, 0);
        for(int end = start; end < m; end++) {
            for(int i = 0; i < n; i++) {
                temp[i] += a[i][end];
            }
            ans = max(ans, maxSumKadane(temp));
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> a = {
        {-1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 10, 1, 3},
        {-4, -1, 1, 7, -6}
    };
    cout << maxSumNaive(a) << endl;
    cout << maxSum(a) << endl;
    return 0;
}

