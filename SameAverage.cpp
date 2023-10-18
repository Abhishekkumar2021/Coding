#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> &arr, int k){
    int result = 0, curSum = 0;
    int n = arr.size();
    unordered_map<int, int> mp;
 
    for (int i = 0; i < n; i++) {
        curSum += (arr[i] - k);
        if (curSum == 0)
            result++;
        if (mp.find(curSum) != mp.end())
            result += mp[curSum];
        mp[curSum]++;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr = {0, 4, 3, -1};
    int k = 2;
    cout << solution(arr, k) << endl;
    return 0;
}
