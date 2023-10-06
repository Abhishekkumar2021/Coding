#include<bits/stdc++.h>
using namespace std;

class FenwickTree{
    vector<long long> bit;
    int n;
    public:
    int lsb(int i){
        return (i & (-i));
    }
    FenwickTree(int x){
        n = x;
        bit.resize(n+1, 0);
    }

    // Query
    long long pre(int i){
        long long ans = 0;
        while(i>0){
            ans += bit[i];
            i = i - lsb(i);
        }
        return ans;
    }

    // Update
    void update(int i, int add){
        while(i<=n){
            bit[i] += add;
            i += lsb(i);
        }
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    FenwickTree f(n);
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int a, b, u;
            cin>> a>>b>>u;
            // Two updates
            f.update(a, u);
            f.update(b+1, -u);
        }else{
            int c;
            cin >> c;
            cout << arr[c-1] + f.pre(c) << endl;
        }
    }
}