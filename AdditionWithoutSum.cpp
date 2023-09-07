#include<bits/stdc++.h>
using namespace std;

int addNumbers(int A, int B) {
    int ans = 0;
    bool c = 0;
    for(int i=0; i<32; i++){
        bool a = (A>>i) & 1;
        bool b = (B>>i) & 1;

        bool sum = a^b^c;
        c = a&b || a&c || b&c;
        if(sum) ans = ans | (1<<i);
    }
    return ans;
}
