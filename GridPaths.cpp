#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i=0; i<n; i++){
        cin >> grid[i];
    }
    if(grid[0][0] == '*' || grid[n-1][n-1] == '*'){
        cout << 0 << "\n";
        return 0;
    }
    const int mod = 1e9 + 7;
    vector<long long> curr(n+1, 0), prev(n+1, 0);
    for(int i=n-1; i>=0; i--){
        for(int j=n-1; j>=0; j--){
            if(i == n-1 && j == n-1) curr[j] = 1;
            else if(grid[i][j] == '*') curr[j] = 0;
            else curr[j] = (curr[j+1] + prev[j])%mod;
        }
        prev = curr;
    }
    cout << curr[0] << "\n";
    return 0;
} 
