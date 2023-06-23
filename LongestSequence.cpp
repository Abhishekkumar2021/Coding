#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    map<int, int> m;
    int ans = 1;
    for(int i=0; i<n; i++){
        m[arr[i]] = m[arr[i]-1] + 1;
        ans = max(ans, m[arr[i]]);
    }
    return ans;
}