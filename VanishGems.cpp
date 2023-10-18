#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2));
    for(int i=0; i<n; i++) cin >> arr[i][0] >> arr[i][1];
    // sort
    sort(arr.begin(), arr.end(), [&](vector<int> &a, vector<int> &b){
        if(a[1] < b[1]) return true;
        if(a[1] == b[1] && a[0] > b[0]) return true;
        return false;
    });
    int ans = 0;
    int i = 0, j = n-1;
    while(i<j){
        if(arr[i][0] != 0){
            int cnt = arr[i][0];
            while(cnt-- && j>i){
                ans += arr[j][1];
                j--;
            }
        }
        i++;
    }
    cout << ans << "\n";
    return 0;
}
