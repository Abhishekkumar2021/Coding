#include<bits/stdc++.h>
using namespace std;

vector<long long> createSequence(long long n){
    // Write your code here.
    queue<long long> q;
    vector<long long> v;
    if(n>=2){
        q.push(2);
        v.push_back(2);
    }
    if(n>=5){
        q.push(5);
        v.push_back(5);
    }

    while(!q.empty()){
        long long x = q.front();
        q.pop();
        long long a = x*10+2;
        long long b = x*10+5;
        if(a<=n){
            q.push(a);
            v.push_back(a);
        }
        if(b<=n){
            q.push(b);
            v.push_back(b);
        }
    }
    return v;
}