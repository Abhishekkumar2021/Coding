#include<bits/stdc++.h>
using namespace std;

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), [](pair<int, int> a, pair<int, int> b){
        return (double)a.second/a.first > (double)b.second/b.first;
    });
    double ans = 0;
    for(int i=0;i<n;i++){
        if(w==0){
            break;
        }
        if(items[i].first<=w){
            ans+=items[i].second;
            w-=items[i].first;
        }
        else{
            ans+=((double)items[i].second/items[i].first)*w;
            w=0;
        }
    }
    return ans;  
}