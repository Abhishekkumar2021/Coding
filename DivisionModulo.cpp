#include<bits/stdc++.h>
using namespace std;

/*
You are given three integers a, b and m. You have to calculate (a/b)%m under modulo operation.

Approach:
    1. (a/b)%m = (a%m * b^-1%m)%m
    2. b^-1%m = b^(m-2)%m
    3. (a/b)%m = (a%m * b^(m-2)%m)%m

    Time Complexity: O(log(m))

Ques 02 -  You are given a, b, c and m and you have to find out ((a^b)/c)%m.


*/


/*
    Modular Exponentiation
    Time Complexity: O(log(b))
    Algo - 
        1. If b is even then a^b = (a^2)^(b/2)
        2. If b is odd then a^b = a * (a^2)^(b/2)
    
    Example -
        2^10 = (2^2)^5 = (4^2)^2 = (16^2)^1 = 16 * (256)^0 = 16 * 1 = 16
*/
long long exp(int a, int b, int m){
    long long res = 1;
    while(b){
        if(b&1){
            res = (res*a)%m;
        }
        a = (a*a)%m;
        b = b>>1;
    }

    /*
    Dry run:
        a = 2, b = 10, m = 5
        res = 1
        b = 1010
        b&1 = 0
        a = 4
        b = 101
        b&1 = 1
        res = 4
        a = 16
        b = 10
        b&1 = 0
        a = 256
        b = 1
        b&1 = 1
        res = 4 * 256 = 1024
        a = 1024
        b = 0
        b&1 = 0
        res = 4 * 256 = 1024
        return 4
    */
    return res;
}


int solve(int a, int b, int c, int m){
    long long x = exp(a, b, m);
    long long y = exp(c, m-2, m);
    return (x*y)%m;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b, c, m;
        cin>>a>>b>>c>>m;
        cout<<solve(a, b, c, m)<<endl;
    }
}