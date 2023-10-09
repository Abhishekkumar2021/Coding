#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    long long sum;
    long long pre;
    long long suf;
    long long seg;

    // Default constructor
    Node(){
        sum = 0;
        pre = 0;
        suf = 0;
        seg = 0;
    }

    // Parameterized constructor
    Node(long long sum, long long pre, long long suf, long long seg){
        this->sum = sum;
        this->pre = pre;
        this->suf = suf;
        this->seg = seg;
    }
};

class SegmentTree
{
    vector<Node> tree;
    vector<int> arr;
    int n;

    // Build the tree
    void build(int start, int end, int node)
    {
        if (start == end)
        {
            if(arr[start] > 0){
                tree[node] = Node(arr[start], arr[start], arr[start], arr[start]);
            }
            else{
                tree[node] = Node(arr[start], 0, 0, 0);
            }
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * node + 1);
        build(mid + 1, end, 2 * node + 2);

        // Merge the children
        Node left = tree[2*node + 1];
        Node right = tree[2*node + 2];
        tree[node].sum = left.sum + right.sum;
        tree[node].pre = max(left.pre, left.sum + right.pre);
        tree[node].suf = max(right.suf, right.sum + left.suf);
        tree[node].seg = max({left.seg, right.seg, left.suf + right.pre});
    }
    Node query(int start, int end, int node, int l, int r)
    {
        // No overlap
        if (start > r || end < l)
        {
            return Node(0, 0, 0, 0);
        }

        // Complete overlap
        if (start >= l && end <= r)
        {
            return tree[node];
        }

        // Partial overlap
        int mid = (start + end) / 2;
        Node left = query(start, mid, 2 * node + 1, l, r);
        Node right = query(mid + 1, end, 2 * node + 2, l, r);

        // Merge the children
        Node ans;
        ans.sum = left.sum + right.sum;
        ans.pre = max(left.pre, left.sum + right.pre);
        ans.suf = max(right.suf, right.sum + left.suf);
        ans.seg = max({left.seg, right.seg, left.suf + right.pre});
        return ans;
    }
    void update(int start, int end, int node, int index, int val)
    {
        if (start == end)
        {
            if(val > 0){
                tree[node] = Node(val, val, val, val);
            }
            else{
                tree[node] = Node(val, 0, 0, 0);
            }
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
        {
            update(start, mid, 2 * node + 1, index, val);
        }
        else
        {
            update(mid + 1, end, 2 * node + 2, index, val);
        }
        
        // Merge the children
        Node left = tree[2*node + 1];
        Node right = tree[2*node + 2];
        tree[node].sum = left.sum + right.sum;
        tree[node].pre = max(left.pre, left.sum + right.pre);
        tree[node].suf = max(right.suf, right.sum + left.suf);
        tree[node].seg = max({left.seg, right.seg, left.suf + right.pre});
    }
public:
    void update(int index, int val)
    {
        update(0, n - 1, 0, index, val);
    }
    long long query(int l, int r)
    {
        return query(0, n - 1, 0, l, r).seg;
    }
    void build(vector<int> &arr){
        n = arr.size();
        tree.resize(4*n);
        this->arr = arr;
        build(0, n-1, 0);
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
        int idx, val;
        cin >> idx >> val;
        s.update(idx-1, val);
        cout << s.query(0, n-1) << "\n";
    }
    return 0;
}
