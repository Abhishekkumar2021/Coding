#include<bits/stdc++.h>
using namespace std;

long long fact(int n){
    if(n<=1) return 1;
    long long ans = 1;
    for(int i=2; i<=n; i++) ans *= i;
    return ans;
}

void generate(string &s, int idx, int n, string &curr, set<string> &res, vector<bool> &vis){
    if(idx == n){
        res.insert(curr);
        return;
    }

    for(int i=0; i<n; i++){
        if(!vis[i]){
            vis[i] = true;
            curr.push_back(s[i]);
            generate(s, idx+1, n, curr, res, vis);
            curr.pop_back();
            vis[i] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(26, 0);
    for(auto &c: s) freq[c-'a']++;
    long long ans = fact(n);
    for(int i=0; i<n; i++) ans /= fact(freq[i]);
    cout << ans << "\n";
    set<string> res;
    vector<bool> vis(n, false);
    string curr = "";
    generate(s, 0, n, curr, res, vis);
    for(auto &s: res) cout << s << "\n";
    return 0;
}
