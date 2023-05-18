#include<bits/stdc++.h>
using namespace std;

// polynomial multiplication
vector<int> multiply(vector<int> &a, vector<int> &b, int n){
    // Write your code here.
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> ans(n + n - 1, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans[i + j] += a[i] * b[j];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}