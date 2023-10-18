#include<bits/stdc++.h>
using namespace std;

long long countNumbers(string &num, int n, int prev, bool leading,  bool cons, unordered_map<string, long long> &dp){
    if(n==0) return 1;
    stringstream ss;
    ss << n << "$" << prev << "$" << leading << "$" << cons;
    string key = ss.str();
    if(dp.find(key) != dp.end()) return dp[key];
    int idx = num.length() - n;
    int ub = cons ? (num[idx] - '0') : 9 ;
    long long ans = 0;
    for(int i=0; i<=ub; i++){
        // We can place a zero adjacent to zero only if till now leading is true
        if(i==0 && leading == true){
            ans += countNumbers(num, n-1, i, true, cons && (i == ub), dp);
        }else if(i != prev) ans += countNumbers(num, n-1, i, false, cons && (i == ub), dp);
    }
    return dp[key] = ans;
}

long long countNumbers(long long num){
    string x = to_string(num);
    int n = x.length();
    unordered_map<string, long long> dp;
    return countNumbers(x, n, 10, true, true, dp);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b;
    cin >> a >> b;
    cout << countNumbers(b) - countNumbers(a-1) << "\n";
    return 0;
}
