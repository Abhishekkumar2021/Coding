#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    vector<long long> tree;
    int n;
    void update(int node, int left, int right, int l, int r, int u){
        // No Overlap
        if(right < l || left > r) return;

        // Complete Overlap
        if(left >= l && right <= r){
            tree[node] += u;
            return;
        }

        // Partial overlap
        int mid = (left + right)/2;
        update(2*node+1, left, mid, l, r, u);
        update(2*node+2, mid+1, right, l, r, u);
    }
    long long query(int node, int left, int right, int idx){
        if(left == right){
            return tree[node];
        }
        int mid = (left+right)/2;
        if(idx <= mid){
            return tree[node] + query(2*node+1, left, mid, idx);
        }else{
            return tree[node] + query(2*node+2, mid+1, right, idx);
        }
    }
    public:
    SegmentTree(int x){
        n = x;
        tree.resize(4*n, 0);
    }

    // Update
    void update(int l, int r, int u){
        update(0, 0, n-1, l, r, u);
    }

    // Query
    long long query(int idx){
        return query(0, 0, n-1, idx);
    }
};

int main(){
    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    SegmentTree t(n);
    while(q--){
        int type;
        cin>>type;
        if(type == 1){
            int a, b, u;
            cin>> a>>b>>u;
            t.update(a-1, b-1, u);
        }else{
            int c;
            cin >> c;
            cout << arr[c-1] + t.query(c-1) << endl;
        }
    }
}
