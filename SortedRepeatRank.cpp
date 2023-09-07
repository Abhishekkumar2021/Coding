#include<bits/stdc++.h>
using namespace std;

int exp(int x, int n){
    const int mod = 1000003;
    long long ans = 1;
    while(n>0){
        if(n&1) ans = (ans*x)%mod;
        x = (x*1LL*x)%mod;
        n /= 2;
    }
    return ans;
}



// Characters are repeated
int sortedRank(string s){
    const int mod = 1000003;
    int n = s.size();
    long long ans = 1;
    /*
    Example: 
    s = "ababc"
    a -> 1
    b -> 2
    c -> 1

    a => small = 0
    b => small = 1 
    
    */
    vector<long long> fact(n+1, 1);
    for(int i=2; i<=n; i++) fact[i] = (i*fact[i-1])%mod;
    int curr = n;

    for(int i = 0; i < n; i++){
        // Find number of elements smaller than this character

    }
    return ans;
}

int main(){
    cout << sortedRank("ababc");
}