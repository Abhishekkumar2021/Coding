#include<bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n) {
    int prod = 1;
    while(prod<=n){
        prod *= 3;
    }
    return prod == n;
}

int main(){
    int x = (double)log10(INT_MAX) / log10(3);
    cout<<x<<endl;
}