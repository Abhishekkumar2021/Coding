#include<bits/stdc++.h>
using namespace std;

long long power(long long x, int n){
    const int mod = 1e9 + 7;
    long long ans = 1;
    while(n > 0){
        if(n & 1) ans = (ans*x)%mod;
        x = (x*x)%mod;
        n /= 2;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cout << power(2, n) << "\n";
    return 0;
}
