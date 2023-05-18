#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    
    // We have to find distinct element
    
    for(int i = 0; i < n - 2; i++){
        int j = i + 1, k = n - 1;
        while(j < k){
            if(arr[i] + arr[j] + arr[k] == K){
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while(j < k && arr[j] == arr[j - 1]){
                    j++;
                }
                while(j < k && arr[k] == arr[k + 1]){
                    k--;
                }
            }
            else if(arr[i] + arr[j] + arr[k] < K){
                j++;
            }
            else{
                k--;
            }
        }
        while(i < n - 2 && arr[i] == arr[i + 1]){
            i++;
        }
    }
    return ans;
}