#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int n;
    vector<int> arr;
    vector<long long> tree;
    vector<long long> lazy;
    void build(int node, int left, int right){
        if(left == right){
            tree[node] = arr[left];
            return;
        }

        int mid = left + (right-left)/2;
        build(2*node+1, left, mid);
        build(2*node+2, mid+1, right);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    long long query(int node, int left, int right, int l, int r){
        // This is query
        // If we are at a node which is not updated, then update it's lazy value
        if(lazy[node] != 0){
            tree[node] += (right-left+1)*lazy[node];
            if(left != right){
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }
            lazy[node] = 0;
        }

        // No overlap
        if(right < l || left > r) return 0;

        // Complete overlap
        if(left >= l && right <= r) return tree[node];

        // Partial Overlap
        int mid = left + (right - left)/2;
        long long leftAns = query(2*node+1, left, mid, l, r);
        long long rightAns = query(2*node+2, mid+1, right, l, r);
        return leftAns + rightAns;
    }

    void update(int node, int left, int right, int l, int r, int inc){
        // Here we are doing lazy update
        // If we are at a node which is not updated, then update it's lazy value
        if(lazy[node] != 0){
            tree[node] += (right-left+1)*lazy[node];
            if(left != right){
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }
            lazy[node] = 0;
        }

        // No overlap
        if(right < l || left > r) return;

        // Complete overlap
        if(left >= l && right <= r){
            tree[node] += (right-left+1)*inc;
            if(left != right){
                lazy[2*node+1] += inc;
                lazy[2*node+2] += inc;
            }
            return; 
        }

        // Partial Overlap
        int mid = left + (right - left)/2;
        update(2*node+1, left, mid, l, r, inc);
        update(2*node+2, mid+1, right, l, r, inc);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    public:
    void build(vector<int> arr){
        this->arr = arr;
        n = arr.size();
        tree.resize(4*n);
        lazy.resize(4*n, 0);
        build(0, 0, n-1);
    }

    long long query(int l, int r){
        return query(0, 0, n-1, l, r);
    }

    void update(int l, int r, int inc){
        update(0, 0, n-1, l, r, inc);
    }
};

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    SegmentTree s;
    s.build(arr);
    while(q--){
        char type;
        cin >> type;
        if(type == 'q'){
            int l, r;
            cin >> l >> r;
            cout << s.query(l, r) << "\n";
        }else{
            int l, r, inc;
            cin >> l >> r >> inc;
            s.update(l, r, inc);
        }
    }
    return 0;
}
