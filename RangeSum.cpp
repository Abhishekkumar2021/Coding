#include<bits/stdc++.h>
using namespace std;

int countSubarray(vector<int> &arr, int k){
    int ans = 0;
    int sum = 0;
    int i = 0, j = 0;
    int n = arr.size();
    while(i< n && j < n){
        sum += arr[j];
        while(i< n && sum > k){
            sum -= arr[i];
            i++;
        }
        // Number of subarrays ending at j
        ans += (j-i) + 1;
        j++;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    vector<int> arr = {1};
    cout << countSubarray(arr, -1) << endl;
    return 0;
}

