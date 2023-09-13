#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) x = 1/x;
        long long num = abs(n);

        double ans = 1;
        while(num){
            if(num & 1) ans *= x;
            x *= x;
            num = num/2;
        }
        return ans;
    }
};