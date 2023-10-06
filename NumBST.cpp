#include<bits/stdc++.h>
using namespace std;

long long exp(int x, int n){
    int mod = 1e8 + 7;
    long long ans = 1;
    while(n>0){
        if(n & 1) ans = (ans * x)%mod;
    }
}

long long moduloInverse(int x){
    int mod = 1e8 + 7;
    return exp(x, mod-2);
}

vector<int> numBST(vector<int> nodeValues){
    int mod = 1e8 + 7;
    int maxi = *max_element(nodeValues.begin(), nodeValues.end());
    int size = 2*maxi + 1;
    vector<vector<long long>> dp(size, vector<long long>(size, 1));
    for(int i=2; i<size; i++){
        for(int j=1; j<i; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
        }
    }

    vector<int> ans;
    for(int x: nodeValues){
        int value = (dp[2*x][x]*moduloInverse(x+1))%mod;
        ans.push_back(value);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nodevalues(n);
    for(int i=0; i<n; i++){
        cin >> nodevalues[i];
    }
    vector<int> ans = numBST(nodevalues);
    for(auto x: ans) cout << x << " ";
    cout << endl;

}