#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    cin>>n>>q;
    vector<vector<bool>> forest(n+1, vector<bool>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char ch;
            cin>>ch;
            forest[i][j] = (ch == '*');
        }
    }

    vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + forest[i][j];
        }
    }

    while(q--){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        cout << dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1] << endl;
    }
}