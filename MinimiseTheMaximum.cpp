#include<bits/stdc++.h>
using namespace std;

int count(vector<int> &pos, long double dist){
    int ans = 0;
    int n = pos.size();
    for(int i=0; i<n-1; i++){
        long double possible = (pos[i+1] - pos[i])/dist;
        int x = floor(possible);
        // If possible is and exact integer then take one less
        if(x*dist == pos[i+1] - pos[i]) x--;
        ans += x;
    }
    return ans;
}

long double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
    long double low = 0, high = 1e9;
    long double ans = 0;
    while(high - low > 1e-6){
        long double mid = (low+high)/2;
        int cnt = count(arr, mid);
        if(cnt <= k){
            ans = mid;
            high = mid;
        }
        else low = mid;
    }	
    return ans;
}