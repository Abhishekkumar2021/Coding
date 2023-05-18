#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(long long n){
    // Bitwise palindrome
    // long long rev = 0;
    // long long temp = n;
    // while(temp){
    //     rev <<= 1;
    //     rev |= (temp & 1);
    //     temp >>= 1;
    // }
    // return rev == n;

    // Second method - Bit comparisons
    int i = 63;
    int j = 0;
    // First remove all zeros from the left
    while(i){
        bool bit = n & (1LL << i);
        if(bit) break;
        i--;
    }
    while(j < i){
        bool bitI = n & (1LL << i);
        bool bitJ = n & (1LL << j);
        if(bitI != bitJ) return false;
        i--;
        j++;
    }
    return true;
}
int main(){
    // long long a = 1e18;
    // for(int i=0; i<64; i++){
    //     bool bit = a & (1LL << i);
    //     if(bit) cout << 1;
    //     else cout << 0;
    // }
    long long n = 7;
    cout << isPalindrome(n) << endl;
    return 0;
}