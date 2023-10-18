#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> ans;
    for(auto &x: arr){
        if(ans.empty()) ans.push_back(x);
        else if(x > ans.back()) ans.push_back(x);
        else{
            auto it = lower_bound(ans.begin(), ans.end(), x);
            *it = x;
        }
    }
    cout << ans.size() << "\n";
    return 0;
}
