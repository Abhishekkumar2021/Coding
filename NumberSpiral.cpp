#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        long long y, x;
        cin >> y >> x;
        if(y & 1){
            if(x <= y){
                cout << (y-1)*(y-1) + x << "\n";
            }else{
                if(x & 1){
                    cout << x*x - (y-1) << "\n";
                }else{
                    cout << (x-1)*(x-1) + y << "\n";
                }
            }
        }else{
            if(x <= y){
                cout << y*y - (x-1) << "\n";
            }else{
                if(x & 1){
                    cout << x*x - (y-1) << "\n";
                }else{
                    cout << (x-1)*(x-1) + y << "\n";
                }
            }
        }
    }
    return 0;
}
