#include<bits/stdc++.h>
using namespace std;

// Return Nth term of GP , as answer can be very large output answer % 10^9+7.
// Use recusrion to solve the problem must handle big numbers.

int f(int a, int r, int n){
    if(n == 0) return 1;
    if(n == 1) return a;
    if(n % 2 == 0){
        int x = f(a, r, n/2);
        return (x * x) % 1000000007;
    }
    else{
        int x = f(a, r, n/2);
        return (x * x * r) % 1000000007;
    }
}
int nthTermOfGP(int n, int a, int r) {
    return f(a, r, n-1);
}