#include<bits/stdc++.h>
using namespace std;

/*
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/

int nCr(int n, int r){
    const int mod = 1e9 + 7;
    vector<long long> curr(n+1, 1), prev(n+1, 1);
    for(int i=2; i<=n; i++){
        for(int j = 1; j<i; j++){
            curr[j] = (prev[j] + prev[j-1])%mod;
        }
        prev = curr;
    }
    return curr[r];
}

long long power(long long x,int n){
    const int mod = 1e9 + 7;
	// if(n==0) return 1;
	// if(n==1) return x;
	// long long half = power(x, n/2);
    // if(n%2==0) return (half*half)%mod;
    // return ((x*half)%mod*half)%mod;

    // while loop
    /*
    10^15 = 10^(1 + 2 + 4 + 8) = 10^1 * 10^2 * 10^4 * 10^8
    */
    long long ans = 1;
    while(n>0){
        if(n&1){
            ans = (ans*x)%mod;
        }
        x  = (x*x)%mod;
        n = n>>1;
    }
    return ans;
}

int findCatalan(int n) 
{
    const int mod = 1e9 + 7;
    return (nCr(2*n, n)*1LL*power(n+1, mod-2))%mod;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        cout << nCr(n, r) << endl;
        cout << power(n, r) << endl;
    }

}