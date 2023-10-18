#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> par; // Topmost parent
    vector<long long> size; // Size of the component
    

    // This is based on the question
    long long maxSum;
    vector<int> arr;
    vector<bool> vis;
    vector<long long> sum;
    int n;

    public:
    DSU(vector<int> arr){
        n = arr.size();
        par.resize(n);
        size.resize(n);
        vis.resize(n, false);
        sum.resize(n);
        maxSum = 0;
        this->arr = arr;
        for(int i=0; i<n; i++){
            par[i] = i;
            size[i] = 1;
            sum[i] = arr[i];
        }
    }

    // Find the topmost parent : Path compression
    int find(int node){
        if(par[node] == node) return node;
        return par[node] = find(par[node]);
    }

    // Union of two components
    void join(int x, int y){
        int parX = find(x);
        int parY = find(y);
        if(parX == parY) return;
        if(size[parX] > size[parY]){
            par[parY] = parX;
            size[parX] += size[parY];
            sum[parX] += sum[parY];
            maxSum = max(maxSum, sum[parX]);
        }else{
            par[parX] = parY;
            size[parY] += size[parX];
            sum[parY] += sum[parX];
            maxSum = max(maxSum, sum[parY]);
        }
    }

    void add(int idx){
        vis[idx] = true;
        maxSum = max(maxSum, (long long)arr[idx]);
        if(idx-1>=0 && vis[idx-1]) join(idx, idx-1);
        if(idx+1<n && vis[idx+1]) join(idx, idx+1);
    }

    int maximumSum(){
        return maxSum;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> des(n);
    for(int i=0; i<n; i++){
        cin >> des[i];
        // 0 based indexing
        des[i]--;
    }
    reverse(des.begin(), des.end());
    DSU d(arr);
    vector<int> ans;
    ans.push_back(0);
    d.add(des[0]);
    for(int i=1; i<n; i++){
        ans.push_back(d.maximumSum());
        d.add(des[i]);
    }
    reverse(ans.begin(), ans.end());
    for(auto &x: ans) cout << x << "\n";
    return 0;
}
