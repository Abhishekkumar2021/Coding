#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    long long sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    } 
    vector<bool> prev(sum+1, false), curr(sum+1, false);
    prev[0] = true;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j==0) curr[j] = true;
            else if(arr[i-1] <= j) curr[j] = (prev[j] || prev[j-arr[i-1]]);
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    vector<int> ans;
    for(int i=1; i<=sum; i++) if(curr[i]) ans.push_back(i);
    cout << ans.size() << "\n";
    for(auto &x: ans) cout << x << " ";
    cout << "\n";
    return 0;
}
