#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int n;
    vector<int> arr;
    vector<long long> tree;

    // Build
    void build(int node, int left, int right){
        if(left == right){
            tree[node] = arr[left];
            return ;
        }
    }

    public:
    void build(vector<int> arr){
        build(0, 0, n-1);
    }
};