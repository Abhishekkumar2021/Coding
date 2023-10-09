#include <bits/stdc++.h>
using namespace std;
 
const long long mod = 1e9 + 7;
const long long N = 1e6 + 1;
 
int main() {
    vector<long long > OneBlock(N), TwoBlocks(N);
    OneBlock[1] = TwoBlocks[1] = 1;
 
    for (int i = 2; i <= N; i++) {
        OneBlock[i] = (2 * OneBlock[i - 1] + TwoBlocks[i - 1]) % mod;
        TwoBlocks[i] = (4 * TwoBlocks[i - 1] + OneBlock[i - 1]) % mod;
    }
 
    int t;
    cin >> t;
    while (t--){
        int n; 
        cin >> n;
        cout << (OneBlock[n] + TwoBlocks[n]) % mod << "\n";
    }       
    return 0;
}