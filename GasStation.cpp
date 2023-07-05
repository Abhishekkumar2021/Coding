#include<bits/stdc++.h>
using namespace std;

int canComplete(vector<int> &gas, vector<int> &cost){
    int n = gas.size();
    int totalGas = accumulate(gas.begin(), gas.end(), 0);
    int totalCost = accumulate(cost.begin(), cost.end(), 0);
    if(totalGas<totalCost){
        return -1;
    }
    int currGas = 0;
    int start = 0;
    for(int i=0; i<n; i++){
        currGas += gas[i] - cost[i];

        if(currGas<0){
            start = i+1;
            currGas = 0;
        }
    }
    return start;
}