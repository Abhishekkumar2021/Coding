#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> pre(n+1, 0);
    for(int i=1; i<=n; i++){
        pre[i] = pre[i-1] + arr[i-1];
    }
    
}
