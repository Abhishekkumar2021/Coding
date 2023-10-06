#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    vector<long long> tree;
    vector<int> arr;
    int n;
    // Build
    void build(int node, int left, int right){
        if(left == right){
            tree[node] = arr[left];
            return;
        }

        int mid = left + (right-left)/2;
        build(2*node+1, left, mid);
        build(2*node+2, mid+1, right);
        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

    // Update
    void update(int node, int left, int right, int idx, int dec){
        if(left == right){
            tree[node] -= dec;
            arr[idx] -= dec;
            return;
        }

        int mid = left + (right-left)/2;
        if(idx <= mid) update(2*node+1, left, mid, idx, dec);
        else update(2*node+2, mid+1, right, idx, dec);

        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }

    // Query
    int query(int node, int left, int right, int k){
        // base case
        if(tree[node] < k) return -1;
        if(left == right) return left;

        int mid = left + (right-left)/2;
        int leftAns = query(2*node+1, left, mid, k);
        if(leftAns != -1) return leftAns;
        return query(2*node+2, mid+1, right, k);
    }
    public:
    void build(vector<int> arr){
        n = arr.size();
        tree.resize(4*n);
        this->arr = arr;
        build(0, 0, n-1);
    }
    void update(int idx, int dec){
        update(0, 0, n-1, idx, dec);
    }
    int query(int k){
        return query(0, 0, n-1, k);
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), req(m);
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<m; i++) cin >> req[i];
    SegmentTree t;
    t.build(arr);
    for(int i=0; i<m; i++){
        int idx = t.query(req[i]);
        if(idx == -1) cout << 0 << endl;
        else cout << idx + 1 <<endl;
        if(idx != -1) t.update(idx, req[i]);
    }
}