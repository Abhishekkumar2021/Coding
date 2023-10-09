#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    vector<long long> dp(1e6+1, 0);
    dp[0] = 1;
    const int mod = 1e9 + 7;
    for(int n=1; n<=1e6; n++){
        for(int x = 1; x <= 6; x++){
            if(n >= x) dp[n] = (dp[n] + dp[n-x])%mod;
        }
    }
    int n;
    cin >> n;
    cout << dp[n] << "\n";
    return 0;
}
