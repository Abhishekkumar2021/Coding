#include<bits/stdc++.h>
using namespace std;

int minCost(int i, int j, int c, vector<int> &cuts){
    if(i>j || j-i <= 1) return 0;
    int ans = INT_MAX;
    for(int k=0; k<c; k++){
        if(cuts[k] > i && cuts[k] < j) {
            int left = minCost(i, cuts[k], c, cuts);
            int right = minCost(cuts[k], j, c, cuts);
            int cost = j - i;
            ans = min(ans, left + right + cost);
        }
    }
    return ans;
}

int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    return minCost(0, n, c, cuts);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}
