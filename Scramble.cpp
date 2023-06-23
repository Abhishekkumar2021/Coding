#include<bits/stdc++.h>
using namespace std;

bool scramble(string a, string b, map<string, bool> &mp){
    if(a.size()==0) return false;
    if(a == b) return true;
    int n = a.size();
    string key = a + " " + b;
    if(mp.find(key) != mp.end()) return mp[key];
    for(int len = 1; len<=n-1; len++){
        bool swapped = scramble(a.substr(0, len), b.substr(n-len, len), mp) && scramble(a.substr(len, n-len), b.substr(0, n-len), mp);
        bool not_swapped = scramble(a.substr(0, len), b.substr(0, len), mp) && scramble(a.substr(len, n-len), b.substr(len, n-len), mp);
        if(swapped || not_swapped) return mp[key] = true;
    }
    return mp[key] = false;
}

int main(){
    string a = "great";
    string b = "rgeat";
    map<string, bool> mp;
    cout<<scramble(a, b, mp)<<endl;
    return 0;
}