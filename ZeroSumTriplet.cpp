#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n) {
	// Write your code here
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    // distinct triplets are required
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            if (arr[i] + arr[j] + arr[k] == 0)
            {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                {
                    j++;
                }
                while (j < k && arr[k] == arr[k + 1])
                {
                    k--;
                }
            }
            else if (arr[i] + arr[j] + arr[k] > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return ans;
}