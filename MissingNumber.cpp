#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n-1);
    for(auto &x: arr) cin >> x;
    sort(arr.begin(), arr.end());
    int missing = 1;
    for(auto &x: arr){
        if(x != missing){
            break;
        }else missing++;
    }
    cout << missing << "\n";
    return 0;
}
