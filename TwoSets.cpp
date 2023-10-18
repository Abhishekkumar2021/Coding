#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if(n & 1){
        int x = (n-1)/2;
        if(x & 1){
            cout << "YES\n";
            cout << n/2 + 1 << "\n";
            int i = 1, j = n-1;
            while(i<=j){
                cout << i << " " << j << " ";
                i += 2;
                j -= 2;
            }
            cout << "\n";
            i = 2, j = n-2;
            cout << n/2 << "\n";
            while(i<=j){
                cout << i << " " << j << " ";
                i += 2;
                j -= 2;
            }
            cout << n << "\n";

        }else cout << "NO\n";
    }else{
        int x = n/2;
        if(x & 1) cout << "NO\n";
        else{
            cout << "YES\n";
            cout << n/2 << "\n";
            int i = 1, j = n;
            while(i<=j){
                cout << i << " " << j << " ";
                i += 2;
                j -= 2;
            }
            cout << "\n";
            i = 2, j = n-1;
            cout << n/2 << "\n";
            while(i<=j){
                cout << i << " " << j << " ";
                i += 2;
                j -= 2;
            }
            cout << "\n";
        }
    }
    return 0;
}
