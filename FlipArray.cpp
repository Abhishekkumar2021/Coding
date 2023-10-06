#include<bits/stdc++.h>
using namespace std;

int minElements(const vector<int> &arr){
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<bool> prev(sum+1, false), curr(sum+1, false);
    prev[0] = true;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j==0) curr[j] = true;
            else if(arr[i-1] <= j) curr[j] = prev[j] || prev[j-arr[i-1]];
            else curr[j] = prev[j];
        }
        prev = curr;
    }
    int target = sum/2;
    while(curr[target] == false) target--;

    // Now we have to find out the minimum number of elements required to create a sum of this target
    vector<int> prevDP(target+1, 1e8), currDP(target+1, 1e8);
    prevDP[0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=target; j++){
            if(j==0) currDP[j] = 0;
            else if(arr[i-1] <= j) currDP[j] = min(prevDP[j], 1 + prevDP[j-arr[i-1]]);
            else currDP[j] = prevDP[j];
        }
        prevDP = currDP;
    }
    return curr[target];
}

int main(){
    const vector<int> arr = {8,4,5,7,6,2};
    cout << minElements(arr);
}