#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    long long sum;
    long long prefix;
    Node(){
        sum = 0;
        prefix = 0;
    }
    Node(long long sum, long long prefix){
        this->sum = sum;
        this->prefix = prefix;
    }
};

class SegmentTree{
    int n;
    vector<int> arr;
    vector<Node> tree;
    void build(int node, int left, int right){
        if(left == right){
            tree[node] = Node(arr[left], arr[left] < 0 ? 0: arr[left]);
            return;
        }

        int mid = left + (right-left)/2;
        build(2*node+1, left, mid);
        build(2*node+2, mid+1, right);
        tree[node].sum = tree[2*node+1].sum + tree[2*node+2].sum;
        tree[node].prefix = max(tree[2*node+1].sum + tree[2*node+2].prefix, tree[2*node+1].prefix);
    }

    Node query(int node, int left, int right, int l, int r){
        // No overlap
        if(right < l || left > r) return Node(0, 0);

        // Complete overlap
        if(left >= l && right <= r) return tree[node];

        // Partial Overlap
        int mid = left + (right - left)/2;
        Node leftAns = query(2*node+1, left, mid, l, r);
        Node rightAns = query(2*node+2, mid+1, right, l, r);
        
        // calculate overall answer
        return Node(leftAns.sum + rightAns.sum, max(leftAns.prefix, leftAns.sum + rightAns.prefix));
    }

    void update(int node, int left, int right, int idx, int val){
        if(left == right){
            tree[node] = Node(val, val < 0 ? 0: val);
            arr[idx] = val;
            return;
        }

        int mid = left + (right-left)/2;
        if(idx <= mid) update(2*node+1, left, mid, idx, val);
        else update(2*node+2, mid+1, right, idx, val);
        tree[node].sum = tree[2*node+1].sum + tree[2*node+2].sum;
        tree[node].prefix = max(tree[2*node+1].sum + tree[2*node+2].prefix, tree[2*node+1].prefix);
    }

    public:
    void build(vector<int> arr){
        this->arr = arr;
        n = arr.size();
        tree.resize(4*n);
        build(0, 0, n-1);
    }

    long long query(int l, int r){
        return query(0, 0, n-1, l, r).prefix;
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
    SegmentTree s;
    s.build(arr);
    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) s.update(b-1, c);
        else cout << s.query(b-1, c-1) << "\n";
    }
    return 0;
}