#include<bits/stdc++.h>
using namespace std;

int lis(vector<int> &nums, int n, int &maxi){
    // Base case: If length of array is 1 then it is itself and increasing subsequence
    if(n == 1) return 1;

    int ans = 1;
    for(int i=1; i<n; i++){
        if(nums[i-1] < nums[n-1]){
            ans = max(ans, 1 + lis(nums, i, maxi));
        }
    }

    // check if our global maxi is smaller that the maximum length ending here
    if(ans > maxi) maxi = ans;

    return ans;
}