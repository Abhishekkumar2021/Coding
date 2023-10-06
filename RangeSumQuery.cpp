#include<bits/stdc++.h>
using namespace std;

class FenwickTree{
    vector<long long> bit;
    int n;
    public:
    int lsb(int i){
        return (i & (-i));
    }
    FenwickTree(vector<long long> arr){
        n = arr.size();
        bit.resize(n+1, INT_MAX);

        // Build
        for(int i=1; i<=n; i++){
            bit[i] = min(bit[i],arr[i-1]);
            int par = i + lsb(i);
            if(par <= n) bit[par] = min(bit[par],bit[i]);
        }
    }

    // Query
    long long pre(int i){
        long long ans = INT_MAX;
        while(i>0){
            ans = min(ans,bit[i]);
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
    FenwickTree f(arr);
    while(q--){
        int a, b, c;
        cin>>a>>b>>c;
        if(a == 1){
            f.update(b, c-arr[b-1]);
            arr[b-1] = c;
        }else{
            cout << f.pre(c) - f.pre(b-1) << endl;
        }
    }
}