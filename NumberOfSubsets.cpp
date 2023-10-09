#include<bits/stdc++.h>
using namespace std;

long long exp(long long x, int n){
    long long ans = 1;
    const int mod = 1e9 + 7;
    while(n > 0){
        if(n & 1) ans = (ans*x)%mod;
        x = (x*x)%mod;
        n /= 2;
    }
    return ans;
}

long long moduloInverse(int x){
    const int mod = 1e9 + 7;
    return exp(x, mod - 2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int sum = (n*(n+1))/2;
    if(sum%2 == 1){
        cout << 0 << "\n";
        return 0;
    } 
    int target = sum/2;
    const int mod = 1e9 + 7;
    vector<vector<long long>> dp(n+1, vector<long long>(target+1, 0));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=target; j++){
            if(j==0) dp[i][j] = 1;
            else if(i==0) dp[i][j] = 0;
            else if(i <= j) dp[i][j] = (dp[i-1][j] + dp[i-1][j-i])%mod;
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout << (dp[n][target]*moduloInverse(2))%mod << "\n";
    return 0;
}
