#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int sum = 0;
    unordered_map<int, int> mp;
    mp.insert({0, -1});
    int cnt = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        if(mp.find(sum - k) != mp.end()){
            cnt++;
        }
        mp.insert({sum, i});
    }

    cout << cnt << endl;

}

