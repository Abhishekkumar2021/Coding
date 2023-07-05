#include<bits/stdc++.h>
using namespace std;

// Distribute cookies to k children such that maximum cookie given to a child is minimum

void distribute(int idx, vector<int> &cookie, vector<int> &child, int k, int &ans){
    if(idx == cookie.size()){
        int maxi = INT_MIN;
        for(auto x: child) maxi = max(maxi, x);
        ans = min(ans, maxi);
        return;
    }

    // Current cookie can be given to any of the k children
    for(int i=0; i<k; i++){
        child[i] += cookie[idx];
        distribute(idx+1, cookie, child, k, ans);
        child[i] -= cookie[idx];
    }
}

int distributeCookies(vector<int>& cookies, int k) {
    vector<int> child(k, 0);
    int ans = INT_MAX;
    distribute(0, cookies, child, k, ans);
    return ans;
}

int main(){
    vector<int> cookie = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    vector<int> child(3, 0);
    int k = 3;
}