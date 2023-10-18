#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << "\n";
        return 0;
    }
    if(n == 2 || n == 3){
        cout << "NO SOLUTION\n";
        return 0;
    }
    if(n == 4){
        cout << "2 4 1 3\n";
        return 0;
    }
    vector<int> arr(n);
    int i = 0, j =  n%2 == 0 ? n/2 : n/2 + 1;
    int num = 1;
    while(num <= n){
        if(num & 1){
            arr[i++] = num;
        }else{
            arr[j++] = num;
        }
        num++;
    }

    for(auto &x: arr) cout << x << " ";
    cout << "\n";
    return 0;
}
