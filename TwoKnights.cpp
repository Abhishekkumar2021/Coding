#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        if(i==1) cout << 0 << "\n";
        else if(i==2) cout << 6 << "\n";
        else{
            long long x = i*i;
            cout << (x*(x-1))/2 - 4*(i-1)*(i-2) << "\n";
        }
    }
    return 0;
}
