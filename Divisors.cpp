#include<bits/stdc++.h>
using namespace std;

bool isPossible(int n){
    int oddDivisors = 0;
    int evenDivisors = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i!=0){
            continue;
        }
        int a = i;
        int b = n/i;
        if(a==b){
            if(a%2==0){
                evenDivisors++;
            }
            else{
                oddDivisors++;
            }
        }
        else{
            if(a%2==0){
                evenDivisors++;
            }
            else{
                oddDivisors++;
            }
            if(b%2==0){
                evenDivisors++;
            }
            else{
                oddDivisors++;
            }
        }
    }
    return oddDivisors==evenDivisors;
}