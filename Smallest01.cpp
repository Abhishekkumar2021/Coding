// Given a number find the smallest multiple of it only containing 0 and 1

#include<bits/stdc++.h>
using namespace std;

string smallestMultiple(int a){
    if(a==1) return "1";

    vector<int> dp(a+1, 0);
    dp[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        
    }
}