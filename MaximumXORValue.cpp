#include<bits/stdc++.h>
using namespace std;

long long findValueWhoseXORWithGivenNumberIsMaximum(long long x)
{
	// Write your code here 
    // Max value should not be greater than 2305843009213693935 (2^61 - 1)
	long long ans = 0;
    // We check bits from MSB to LSB
    for(int i=61; i>=0; i--){
        // If the bit is set in x, we set the bit in ans to 0
        // If the bit is not set in x, we set the bit in ans to 1
        if((x&(1LL<<i))==0){
            ans |= (1LL<<i);
        }

        // If the bit is set in x, we check if the value of ans is less than x
        // If the value of ans is less than x, we set the bit in ans to 1
        // If the value of ans is greater than x, we set the bit in ans to 0
        if((x&(1LL<<i)) && (ans<x)){
            ans |= (1LL<<i);
        }

    }
    return ans;
}