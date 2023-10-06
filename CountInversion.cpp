#include<bits/stdc++.h>
using namespace std;

// Two methods
// 1. Using Segment Tree
// 2. Using mergeSort

class SegmentTree{
    private:
    vector<int> tree;
    vector<int> arr;
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
    void update(int node, int left, int right, int idx){
        if(left == right){
            tree[node] += 1;
            return;
        }
        int mid = left + (right-left)/2;
        if(idx <= mid) update(2*node+1, left, mid, idx);
        else update(2*node+2, mid+1, right, idx);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    int query(int node, int left, int right, int l, int r){
        // No overlap
        if(left > r || right < l) return 0;

        // Complete overlap
        if(left >= l && right <= r) return tree[node];

        // Partial Overlap
        int mid = left + (right - left)/2;
        int leftSum = query(2*node+1, left, mid, l, r);
        int rightSum = query(2*node+2, mid+1, right, l, r);
        return leftSum + rightSum;
    }

    public:
    void build(vector<int> arr){
        this->arr = arr;
        int n = arr.size();
        tree.resize(4*n);
        build(0, 0, n-1);
    }
    void update(int idx){
        int n = arr.size();
        update(0, 0, n-1, idx);
    }
    int query(int l, int r){
        int n = arr.size();
        return query(0, 0, n-1, l, r);
    }
}; // It is giving MLE

// Using MergeSort

int merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right){
    int ans = 0;
    int i = left;
    int j = mid + 1;
    int k = left;
    while(i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            k++;
            i++;
        }else{
            ans += mid - i;
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    
    while(i<= mid){
        temp[k] = arr[i];
        k++;
        i++;
    }

    while(j <= right){
        temp[k] = arr[j];
        k++;
        j++;
    }

    for(int i=left; i<=right; i++) arr[i] = temp[i];
}

int mergeSort(vector<int> &arr, vector<int> &temp, int left, int right){
    if(left >= right) return 0;
    int mid = left + (right - left)/2;
    int ans = mergeSort(arr, temp, left, mid);
    ans += mergeSort(arr, temp, mid+1, right);
    ans += merge(arr, temp, left, mid, right);
    cout << left <<" "<< right <<" "<< ans <<" "<< endl;
    return ans;
}

int countInversions(vector<int> &A) {
    int n  = A.size();
    vector<int> temp(n);
    return mergeSort(A, temp, 0, n-1);
}