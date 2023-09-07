#include<bits/stdc++.h>
using namespace std;

int minCoins(vector<int> &value, int n, int target){
    // base case
    // if target == 0 that means its saying that if you want to make a sum of 0 then how many coins are required : ans = 0 coins required
    // if number of coins is 0 but target != 0 means you don't have any coin and you want to make a sum which is non zero. 
    // Actualy it is impossible so as an answer to this we return INF(a big number say 1e7)
    if(target==0) return 0;
    if(n==0) return 1e7;

    // If the current coin value is greater than than our target then we can't take this coin but if it is les than or equal then we have two choice :
    // a) either we take it, 
    // b) Or we don't take it
    if(value[n-1] <= target){
        // If I have taken the current coin the again I am passing n not n-1 because its unbounded knapsack means there is infinite supply of each coin
        // which may lead to taking this current coin again, but if I have made a choce that I don't want thos copin then its clear that you will 
        // never take it in future so pass n-1
        int taken = 1 + minCoins(value, n, target - value[n-1]);
        int notTaken = minCoins(value, n-1, target);
        return min(taken, notTaken);
    }else{
        int notTaken = minCoins(value, n-1, target);
        return notTaken;
    }
}

int minCoins(vector<int> &value, int target){
    int n = value.size();
    vector<int> curr(target+1), prev(target+1);

    // i ==> n , j ==> target
    for(int i=0; i<=n; i++){
        for(int j=0; j<=target; j++){
            // 2 base case
            if(j==0) curr[j] = 0;
            else if(i==0) curr[j] = 1e7;
            else if(value[i-1] <= j) curr[j] = min(1 + curr[j - value[i-1]], prev[j]);
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    return curr[target];
}