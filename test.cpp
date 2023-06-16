#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
        
    unordered_map<int, int> m;
    int sum = 0, ct = 0;
    m.insert({0, -1});
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (m.find(k - sum) != m.end())
            ct++;
        m.insert({sum, i});
    }
    cout << ct << endl;
}