#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &x: arr) cin >> x;
    long long ans = 0;
    for(int i=1; i<n; i++){
        if(arr[i] >= arr[i-1]) continue;
        else{
            ans += arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }
    cout << ans << "\n";
    return 0;
}
