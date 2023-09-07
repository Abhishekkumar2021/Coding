#include<bits/stdc++.h>
using namespace std;

bool possible(int k, vector<int> &pile, int hrs){
    int cnt = 0;
    int n = pile.size();
    for(int i=0; i<n; i++){
        cnt += ceil(pile[i]*1.0/k);
        if(cnt > hrs) return false;
    }
    return true;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());
    int ans = -1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(possible(mid, piles, h)){
            ans = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return ans;
}