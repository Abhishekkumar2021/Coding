#include<bits/stdc++.h>
using namespace std;

vector<string> grayCode(int n){
    if(n == 1) return {"0", "1"};

    vector<string> res = grayCode(n-1);
    vector<string> ans;
    for(auto &s: res){
        ans.push_back("0" + s);
    }
    reverse(res.begin(), res.end());
    for(auto &s: res){
        ans.push_back("1" + s);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> ans = grayCode(n);
    for(auto &s: ans) cout << s << "\n";
    return 0;
}
