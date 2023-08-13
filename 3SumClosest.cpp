#include<bits/stdc++.h>
using namespace std;

int closestSum(vector<int> &arr, int x){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int closest = INT_MAX;
    for(int i=0; i<n-2; i++){
        int j = i+1, k = n-1;
        while(j < k){
            int sum = arr[i] + arr[j] + arr[k];
            if(abs(x-sum) < abs(x-closest)) closest = sum;
            if(sum > x) k--;
            else j++;
        }
    }
    return closest;
}

