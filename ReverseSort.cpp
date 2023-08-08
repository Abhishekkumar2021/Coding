#include <bits/stdc++.h>
using namespace std;

int reverseSort(vector<int> &arr)
{
    int cost = 0;
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int j = min_element(arr.begin() + i, arr.end()) - arr.begin();
        reverse(arr.begin() + i, arr.begin() + j + 1);
        cost += j - i + 1;
    }
    return cost;
}

// ReverseSort engineering
vector<int> getList(int n, int cost, int min)
{
    // base case
    if (n == 1)
        return {min};

    if (cost - 1 >= n - 2 and cost - 1 <= (n * (n - 1)) / 2 - 1)
    {
        vector<int> arr = getList(n - 1, cost - 1, min + 1);
        arr.insert(arr.begin(), min);
        return arr;
    }

    // If the cost for current list lies beyond the bounds for list of length n-1,
    // we calculate the minimum value x to be subtracted from current cost such that
    // c-x lies in the bounds for list of length n-1 and build the list with length n-1 and cost c-x recursively,
    // Now, we reverse the first x-1 elements of the list and add the minimum element at the position x,
    int x = cost - (n * (n - 1)) / 2 + 1;
    vector<int> arr = getList(n - 1, cost - x, min + 1);
    vector<int>::iterator end = arr.begin();  
    // reverse the first x-1 elements of the list
    reverse(arr.begin(), end + x - 1);
    arr.insert(end + x - 1, min);
    return arr;
}

int main()
{
    // vector<int> arr = {7, 3, 2, 1, 5, 4, 6};
    // cout << reverseSort(arr) << endl;
    int test;
    cin >> test;
    while (test--)
    {
        int n, cost;
        cin >> n >> cost;

        // First check possiblity
        if (cost < n - 1 or cost > (n * (n + 1)) / 2 - 1)
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            vector<int> arr = getList(n, cost, 1);
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
}