#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<vector<int>> query(q, vector<int>(3));
    for(int i=0; i<q; i++){
        cin >> query[i][0] >> query[i][1];
        query[i][2] = i;
    }
    int x = floor(sqrt(n));
    sort(query.begin(), query.end(), [&](vector<int> &a, vector<int> &b){
        if(a[0]/x == b[0]/x) return a[1] < b[1];
        return a[0]/x < b[0]/x;
    });
    vector<int> ans(q);
    unordered_map<int, int> m;
    int l = query[0][0], r = query[0][1];
    for(int i=l; i<=r; i++) m[arr[i-1]]++;
    ans[query[0][2]] = m.size();
    
    for(int i=1; i<q; i++){
        int l1 = query[i][0];
        int r1 = query[i][1];
        while(l > l1){
            l--;
            m[arr[l-1]]++;
        }
        while(l < l1){
            m[arr[l-1]]--;
            if(m[arr[l-1]] == 0) m.erase(arr[l-1]);
            l++;
        }
        while(r < r1){
            r++;
            m[arr[r-1]]++;
        }
        while(r > r1){
            m[arr[r-1]]--;
            if(m[arr[r-1]] == 0) m.erase(m[arr[r-1]]);
            r--;
        }
        ans[query[i][2]] = m.size();
    }
    for(auto &x: ans) cout << x << "\n";
    return 0;
}
