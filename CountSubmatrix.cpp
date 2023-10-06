#include<bits/stdc++.h>
using namespace std;

int countSubarray(vector<int> &arr, int target){
    int ans = 0;
    unordered_map<int, int> mp;
    int sum = 0, n = arr.size();
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(mp.find(sum - target) != mp.end()) ans += mp[sum-target];
        mp[sum]++;
    }
    ans +=mp[target];
    return ans;
}

int countSub(vector<vector<int>> &mat, int target){
    int ans = 0;
    int n = mat.size();
    int m = mat[0].size();
    for(int start = 0; start < n; start++){
        vector<int> arr(m, 0);
        for(int row = start; row < n; row++){
            for(int col = 0; col < m; col++){
                arr[col] += mat[row][col];
            }
            ans += countSubarray(arr, target);
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1, -1, 2, -2, 3, 4, 2, -4, -5};
    int target = 0;
    // ans = 4
    cout << countSubarray(arr, target) << endl;
}