#include<bits/stdc++.h>
using namespace std;

// class Node{
//     public:
//     int min;
//     int max;
//     Node(){
//         min = INT_MAX;
//         max = INT_MIN;
//     }
//     Node(int a, int b){
//         min = a;
//         max = b;
//     }
// };

// class SegmentTree{
//     int n;
//     vector<int> arr;
//     vector<Node> tree;
//     void build(int node, int left, int right){
//         if(left == right){
//             tree[node] = Node(arr[left], arr[left]);
//             return;
//         }

//         int mid = left +(right-left)/2;
//         build(2*node+1, left, mid);
//         build(2*node+2, mid+1, right);
        
//         tree[node].max = max(tree[2*node+1].max, tree[2*node+2].max);
//         tree[node].min = min(tree[2*node+1].min, tree[2*node+2].min);
//     }

//     long long query(int node, int left, int right, int a, int b){
//         // No overlap
//         if(tree[node].max < a || tree[node].min > b) return 0;

//         // Complete overlap
//         if(a <= tree[node].min  && tree[node].max <= b) return right - left + 1;

//         // Partial Overlap
//         int mid = left + (right - left)/2;
//         int leftAns = query(2*node + 1, left, mid, a, b);
//         int rightAns = query(2*node + 2, mid + 1, right, a, b);
//         return leftAns + rightAns;
//     }

//     void update(int node, int left, int right, int idx, int val){
//         if(left == right){
//             tree[node] = Node(val, val);
//             arr[idx] = val;
//             return;
//         }

//         int mid = left + (right-left)/2;
//         if(idx <= mid) update(2*node+1, left, mid, idx, val);
//         else update(2*node+2, mid+1, right, idx, val);
        
//         tree[node].max = max(tree[2*node+1].max, tree[2*node+2].max);
//         tree[node].min = min(tree[2*node+1].min, tree[2*node+2].min);
//     }

//     public:
//     void build(vector<int> arr){
//         this->arr = arr;
//         n = arr.size();
//         tree.resize(4*n);
//         build(0, 0, n-1);
//     }

//     long long query(int a, int b){
//         return query(0, 0, n-1, a, b);
//     }

//     void update(int idx, int val){
//         update(0, 0, n-1, idx, val);
//     }
// };

// This is for ordered_set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    ordered_set<pair<int, int>> set;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
        set.insert({arr[i], i});
    } 
    // SegmentTree s;
    // s.build(arr);
    while(q--){
        char type;
        cin >> type;
        if(type == '?'){
            int a, b;
            cin >> a >> b;
            // cout << s.query(a, b) << "\n";
            cout << set.order_of_key({b+1, 0}) - set.order_of_key({a, 0}) << "\n";
        }else{
            int idx, val;
            cin >> idx >> val;
            // s.update(idx-1, val);
            set.erase({arr[idx-1], idx-1});
            arr[idx-1] = val;
            set.insert({arr[idx-1], idx-1});
        }
    }
    return 0;
}