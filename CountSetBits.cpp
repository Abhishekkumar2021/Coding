#include<bits/stdc++.h>
using namespace std;

/*
Example 
n = 6
0 => 000
1 => 001
2 => 010
3 => 011
4 => 100
5 => 101
6 => 110
*/
int countBits(int n){
    if(n==0) return 0;
    int x = log2(n);
    int ans = x*pow(2,x-1);
    int rem = n - pow(2,x) + 1;
    ans += rem + countBits(n-pow(2,x));
}