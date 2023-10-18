#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if(a < b) swap(a, b);
        if(a > 2*b) cout << "NO\n";
        else{
            a %= 3;
            b %= 3;
            if((a == 1 && b == 2) || (a == 2 && b == 1)  || (a == 0 && b == 0)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}
