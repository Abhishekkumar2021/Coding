#include<bits/stdc++.h>
using namespace std;

/*
N Keys we can press
Possible operations:
1. Print A
2. Paste
3. Select All
4. Copy
*/

long long int optimalKeys(int curr, int n, int clip){
    if(n==0) return 0;

    // Can paste only if something is copied
    if(clip==0){
        // Select all and copy
        int copyAll = curr + optimalKeys(curr, n-2, curr);
        // paste
        int paste = curr + clip + optimalKeys(curr+clip, n-1, clip);
        // print A
        int printA = curr + 1 + optimalKeys(curr+1, n-1, clip);
        return max(copyAll, max(paste, printA));
    }else{
        // can copy only if nothing is copied
        
    }
    
    
}

long long int optimalKeys(int n){
    if(n==1) return 1;
    
    
}