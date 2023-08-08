#include<bits/stdc++.h>
using namespace std;

int minLights(vector<int> &status, int power){
    int n = status.size();
    int prev = power-1;
    while(prev>=0 && status[prev] == 0) prev--;
    if(prev == -1) return -1;
    int ans = 1;
    while(prev < n){
        if(prev + power >= n) return ans;
        int next = min(prev + 2*power-1, n-1);
        while(next != prev && status[next] == 0) next--;
        if(next == prev) return -1;
        prev = next;
        ans++;
    }
    return ans;
}