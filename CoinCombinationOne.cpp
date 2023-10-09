#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<long long> dp(sum+1, 0);
    dp[0] = 1;
    const int mod = 1e9+7;
    for(int i=1; i<=sum; i++){
        for(int j=0; j<n; j++){
            if(arr[j] <= i) dp[i] = (dp[i] + dp[i - arr[j]])%mod;
        }
    }
    cout << dp[sum] << "\n";
    return 0;
}
