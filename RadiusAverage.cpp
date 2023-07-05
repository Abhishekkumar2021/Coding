#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n,0);
        sum[0] = nums[0];
        for(int i=1; i<n; i++){
            sum[i] = sum[i-1]+nums[i];
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            int prev = i-k;
            int next = i+k;
            if(prev<0 || next>=n) ans.push_back(-1);
            else {
                if(prev==0) ans.push_back(sum[next]/(2*k+1));
                else ans.push_back((sum[next]-sum[prev-1])/(2*k+1));
            }

        }

        return ans;
    }
};