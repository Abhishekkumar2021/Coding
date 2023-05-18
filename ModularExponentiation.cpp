#include<bits/stdc++.h>
using namespace std;

int exp(int a, int n){
    if(n==0){
        return 1;
    }
    int mod = 1e9+7;
    int res = 1;
    int half = exp(a, n/2);
    if(n%2==0){
        res = (half%mod * half%mod)%mod;
    }
    else{
        res = (half%mod * half%mod * a%mod)%mod;
    }
    return (res+mod)%mod;
}


int modularExponentiation(int x, int n, int m) {
	// Write your code here.
	long long ans = 1;
	while(n>0){
        if(n%2==1){
            ans = (ans*x)%m;
        }
        x = (x*x)%m;
        n = n/2;
    }
    return (ans+m)%m;
}

int NthTermGP(int a, int r, int n){
    // Write your code here
    int mod = 1e9+7;
    int res = exp(r, n-1);
    res = (res%mod * a%mod)%mod;
    return (res+mod)%mod;
}