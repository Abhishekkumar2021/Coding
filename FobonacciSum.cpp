/*
Problem Statement
Given two integers, 'N' and 'M', your task is to find the sum of Fibonacci numbers
between 'fib(N)' and 'fib(M)' where 'fib(N)' represents the Nth Fibonacci number and
'fib(M)' represents the Mth Fibonacci number. The sum is given by sum(N, M) = fib(N) +
fib(N+1) + fib(N+2) ... fib(M). Since the answer could be large, so you have to return the
sum modulo 10^9 + 7.
*/
#include<bits/stdc++.h>
using namespace std;

int fiboSum(int n, int m){
    int mod = 1000000007;
    int a = 0, b = 1, c = 1;
    int sum = 0;
    for(int i = 1; i <= m; i++){
        if(i >= n){
            sum = (sum + c) % mod;
        }
        c = (a + b) % mod;
        a = b;
        b = c;
    }
    return sum;
}