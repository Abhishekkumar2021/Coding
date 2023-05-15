#include <bits/stdc++.h>
using namespace std;

vector<int> findTriplets(vector<int> &arr, int n)
{
    vector<int> v;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j];
            if (sum == arr[k])
                return {arr[i], arr[j], arr[k]};
            else if (sum < arr[k])
                j++;
            else
                k--;
        }
    }
    return v;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;
    vector<int> ans = findTriplets(arr, n);
    if (ans.size() == 0)
        cout << "No such triplet found\n";
    else
    {
        for (auto i : ans)
            cout << i << " ";
    }
    return 0;
}