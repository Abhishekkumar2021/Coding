#include <bits/stdc++.h>
using namespace std;

int minTransactions(int k, vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    if (sum % n != 0)
        return -1;
    int target = sum / n;
    int l = 0, r = n-1;
    int ans = 0;
    sort(arr.begin(), arr.end());
    while (l < r)
    {
        if (arr[l] == target)
            l++;
        else if (arr[r] == target)
            r--;
        else if (arr[l] < target && arr[r] > target)
        {
            arr[l] += k;
            arr[r] -= k;
            ans++;
        }
        else if (arr[l] > target)
            l++;
        else if (arr[r] < target)
            r--;
    }
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != target)
            return -1;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cout << minTransactions(k, arr) << endl;
    }
}

/*
4
4 2
4 6 6 8
3 3
4 2 6
4 1
3 3 7 3
4 2
3 3 3 3
*/