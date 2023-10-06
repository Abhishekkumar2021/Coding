#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    vector<int> arr;
    vector<long long> tree;
    int n;
    void build(int node, int left, int right){
        if(left == right){
            tree[node] = arr[left];
            return;
        }

        int mid = (left+right)/2;
        build(2*node+1, left, mid);
        build(2*node+2, mid+1, right);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    void update(int node, int left, int right, int idx, int value){
        if(left == right){
            tree[node] = value;
            arr[idx] = value;
            return;
        }
        int mid = (left+right)/2;
        if(idx <= mid) update(2*node+1, left, mid, idx, value);
        else update(2*node+2, mid+1, right, idx, value);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    int query(int node, int left, int right, int k){
        if(left == right) return left;
        int mid = (left+right)/2;
        if(tree[2*node+1] >= k) return query(2*node+1, left, mid, k);
        else return query(2*node+2, mid+1, right, k - tree[2*node+1]);
    }

    public:
    // Build
    void build(vector<int> arr){
        n = arr.size();
        this->arr = arr;
        tree.resize(4*n);
        build(0, 0, n-1);
    }

    void update(int idx, int value){
        update(0, 0, n-1, idx, value);
    }
    int query(int k){
        return query(0, 0, n-1, k);
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> arr(n), pos(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    for(int i=0; i<n; i++) cin >> pos[i];
    vector<int> nodes(n, 1);
    SegmentTree t;
    t.build(nodes);
    for(int i=0; i<n; i++){
        int idx = t.query(pos[i]);
        cout << arr[idx] << endl;
        t.update(idx, 0);
    }
}