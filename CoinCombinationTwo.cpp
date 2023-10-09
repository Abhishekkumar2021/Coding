#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<long long> prev(sum+1, 0), curr(sum+1, 0);
    const int mod = 1e9 + 7;
    prev[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j==0) curr[j] = 1;
            else if(arr[i-1] <= j) curr[j] = (prev[j] + curr[j-arr[i-1]])%mod;
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    vector<int> dp(1e6, 0);
    cout << curr[sum] << "\n";
    return 0;
}
