#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    int curr = 1;
    for(int i=1; i<n; i++){
        if(s[i] == s[i-1]){
            curr++;
        }else{
            ans = max(ans, curr);
            curr = 1;
        }
    }
    ans = max(ans, curr);
    cout << ans << "\n";
    return 0;
}
