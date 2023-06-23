#include<bits/stdc++.h>
using namespace std;

int f(int n, int curr, int clipboard, bool canCopy){
    if(curr==n) return 0;

    if(curr > n) return 1e5;

    // Choice diagram
    if(canCopy){
        int copied = 1 + f(n, curr, curr, false);
        int pasted = 1 + f(n, curr + clipboard, clipboard, true);
        return min(copied, pasted);
    }

    int pasted = 1 + f(n, curr + clipboard, clipboard, true);
    return pasted;  
}

int minSteps(int n){
    if(n==1) return 0;

    return 1 + f(n, 1, 1, false);
}