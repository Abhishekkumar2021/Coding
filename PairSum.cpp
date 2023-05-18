/*
You are given an integer array 'ARR' of size 'N' and an
integer 'S'. Your task is to return the list of all pairs of
elements such that each sum of elements of each pair
equals 'S'.
Note:
Each pair should be sorted i.e the first
value should be less than or equals to the
second value.
Return the list of pairs sorted in non-
decreasing order of their first value. In
case if two pairs have the same first value,
the pair with a smaller second value should
come first.
*/
#include<bits/stdc++.h>
using namespace std;

bool comparator(vector<int> a, vector<int> b){
    if(a[0] == b[0]){
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
vector<vector<int>> pairSum(vector<int> &arr, int sum){
   // Write your code here.
    int n = arr.size();
    vector<vector<int>> ans;
    map<int, int> m;
    for(int i=0; i<n; i++){
         if(m.find(sum-arr[i]) != m.end()){
            for(int j=0; j<m[sum-arr[i]]; j++){
                ans.push_back({min(arr[i], sum-arr[i]), max(arr[i], sum-arr[i])});
            }
         }
         m[arr[i]]++;
    }

    sort(ans.begin(), ans.end());
    return ans;
}