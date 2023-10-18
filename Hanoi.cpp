#include<bits/stdc++.h>
using namespace std;

void hanoi(int n, int src, int des, vector<pair<int, int>> &ans){
    if(n==1){
        ans.push_back({src, des});
        return;
    }

    int aux = 6 - (src+des);
    hanoi(n-1, src, aux, ans);
    ans.push_back({src, des});
    hanoi(n-1, aux, des, ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    hanoi(n, 1, 3, ans);
    cout << ans.size() << "\n";
    for(auto &p: ans) cout << p.first << " " << p.second << "\n";
    return 0;
}
