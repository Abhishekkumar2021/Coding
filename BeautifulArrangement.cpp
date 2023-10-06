#include<bits/stdc++.h>
using namespace std;

vector<int> beautiful(int n, int k){
    vector<int> ans;
    int l = 1, r = n;
    for(int i=0; i<k-1; i++){
        if(i%2 == 0) ans.push_back(l), l++;
        else ans.push_back(r), r--;
    }
    while(l<=r) ans.push_back(l), l++;
    return ans;
}