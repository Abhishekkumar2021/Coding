#include<bits/stdc++.h>
using namespace std;

// Brute solutions is generate all possible arrangements and then calculate the number of rides ---> O(n!.n)
// Optimized way is to convert this problem from permutation to subset 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, cap;
    cin >> n >> cap;
    vector<int> weight(n);
    for(int i=0; i<n; i++) cin >> weight[i];
    vector<pair<int, int>> dp(1<<n);
    dp[0] = {1, 0};
    for(int s = 1; s< (1<<n); s++){
        // s => set of persons
        dp[s] = {n+1, 0};
        for(int j=0; j<n; j++){
            if(s & (1<<j)){ // If jth element is there in set 
                auto remaining = dp[s^(1<<j)]; // removing the jth element from set
                if(remaining.second + weight[j] <= cap){
                    remaining.second += weight[j];
                }else{
                    remaining.first += 1; // jth element can't fit into that ride
                    remaining.second = weight[j];
                }
                dp[s] = min(dp[s], remaining);
            }
        }
    }
    cout << dp[(1<<n) - 1].first << "\n";
    return 0;
}
