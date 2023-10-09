#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    if(n <= 9){
        cout << 1 << "\n";
        return 0;
    }
    vector<long long> dp(n+1, INT_MAX);
    for(int i=0; i<=n; i++){
        if(i < 10) dp[i] = 1;
        else{
            int num = i;
            while(num > 0){
                int dig = num%10;
                if(dig <= i && dig != 0) dp[i]  = min(dp[i], 1 + dp[i-dig]);
                num /= 10;
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}
