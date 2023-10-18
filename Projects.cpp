#include<bits/stdc++.h>
using namespace std;

class interval{
    public:
    int start, end, val;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<interval> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i].start >> arr[i].end >> arr[i].val;
    
    // sort all the intervals on the basis of ending time
    sort(arr.begin(), arr.end(), [](interval &a, interval &b){
        return a.start <= b.start;
    });
    long long ans = INT_MIN;
    vector<long long> dp(n+1, 0);
    // dp[0] = arr[0].val;
    // for(int i=1; i<n; i++){
    //     dp[i] = arr[i].val;
    //     for(int j=0; j<i; j++){
    //         if(arr[j].end < arr[i].start && dp[j] + arr[i].val > dp[i]) dp[i] = dp[j] + arr[i].val;
    //     }
    //     ans = max(ans, dp[i]);
    // }
    // cout << ans << "\n";
    for(int i=n-1; i>=0; i--){
        // Two case possible 
        // Either not take current
        // Or take : then some of the intervals will get blocked
        int left = i, right = n-1, ans = i;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(arr[mid].start > arr[i].end){
                ans = mid;
                right = mid - 1;
            }else left = mid + 1;
        }
        dp[i] = max(dp[i+1], arr[i].val + dp[ans]);
    }
    cout << dp[0] << "\n";
    return 0;
}
