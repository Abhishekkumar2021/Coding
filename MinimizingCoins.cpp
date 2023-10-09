#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<long long> curr(sum+1, 0), prev(sum+1, 1e10);
    prev[0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j==0) curr[0] = 0;
            else if(arr[i-1] <= j) curr[j] = min(prev[j], 1 + curr[j-arr[i-1]]);
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    cout << (curr[sum] == 1e10 ? -1 : curr[sum]) << "\n";
    return 0;
}
