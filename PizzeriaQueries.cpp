#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int n;
    vector<int> arr;
    vector<long long> tree;
    void build(int node, int left, int right){
        if(left == right){
            tree[node] = arr[left];
            return;
        }

        int mid = left + (right-left)/2;
        build(2*node+1, left, mid);
        build(2*node+2, mid+1, right);
        tree[node] = min(tree[2*node+1], tree[2*node+2]);
    }

    long long query(int node, int left, int right, int l, int r){
        // No overlap
        if(right < l || left > r) return INT_MAX;

        // Complete overlap
        if(left >= l && right <= r) return tree[node];

        // Partial Overlap
        int mid = left + (right - left)/2;
        long long leftAns = query(2*node+1, left, mid, l, r);
        long long rightAns = query(2*node+2, mid+1, right, l, r);
        return min(leftAns, rightAns);
    }

    void update(int node, int left, int right, int idx, int val){
        if(left == right){
            tree[node] = val;
            arr[idx] = val;
            return;
        }

        int mid = left + (right-left)/2;
        if(idx <= mid) update(2*node+1, left, mid, idx, val);
        else update(2*node+2, mid+1, right, idx, val);
        tree[node] = min(tree[2*node+1], tree[2*node+2]);
    }

    public:
    void build(vector<int> arr){
        this->arr = arr;
        n = arr.size();
        tree.resize(4*n);
        build(0, 0, n-1);
    }

    long long query(int l, int r){
        return query(0, 0, n-1, l, r);
    }

    void update(int idx, int val){
        update(0, 0, n-1, idx, val);
    }
};

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    // Two min segment trees have to be build 
    SegmentTree prev, next;
    for(int i=1; i<=n; i++){
        arr[i-1] -= i;
    }
    prev.build(arr);
    for(int i=1; i<=n; i++){
        arr[i-1] += 2*i;
    }
    next.build(arr);
    while(q--){
        int type;
        cin >> type;
        if(type == 2){
            int idx;
            cin >> idx;
            long long a = prev.query(0, idx-1) + idx;
            long long b = next.query(idx, n-1) - idx;
            cout << min(a, b) << "\n";
        }else{
            int idx, val;
            cin >> idx >> val;
            prev.update(idx - 1, val-idx);
            next.update(idx - 1, val+idx);
        }
    }
    return 0;
}
