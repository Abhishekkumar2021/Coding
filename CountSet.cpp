#include<bits/stdc++.h>
using namespace std;

int setCount(int n){
    // base case
    if(n==0) return 0;

    int x = log2(n);
    int diff = n - (pow(2, x)-1);
    return pow(2, x-1)*x + diff + setCount(diff-1);
}