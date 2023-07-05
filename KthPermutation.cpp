#include<bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) {
    vector<int> arr(n);
    int fact = 1;
    for(int i = 0; i < n; i++){
        arr[i] = i + 1;
        fact *= (i + 1);
    }
    k--;
    string ans = "";
    while(n){
        fact /= n;
        int index = k / fact;
        ans += to_string(arr[index]);
        arr.erase(arr.begin() + index);
        k %= fact;
        n--;
    }
    return ans;
}