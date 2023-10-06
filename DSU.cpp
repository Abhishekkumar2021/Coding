// Disjoint Set Union
#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> par; // Topmost parent
    vector<int> size; // Size of the component

    // This is based on the question
    vector<int> maxi;
    int n;

    public:
    DSU(int x){
        n = x;
        par.resize(n+1);
        size.resize(n+1);
        maxi.resize(n+1);
        for(int i=1; i<=n; i++){
            par[i] = i;
            size[i] = 1;
            maxi[i] = i; 
        }
    }

    // Find the topmost parent
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
            maxi[parX] = max(maxi[parX], maxi[parY]);
        }else{
            par[parX] = parY;
            size[parY] += size[parX];
            maxi[parY] = max(maxi[parX], maxi[parY]);
        }
    }

    // Extra functions
    // Number of components
    int numComponents(){
        int ans = 0;
        for(int i=1; i<=n; i++) if(par[i] == i) ans++;
        return ans;
    }
    
    int sumOfMax(){
        int ans = 0;
        for(int i=1; i<=n; i++) if(par[i] == i) ans += maxi[i];
        return ans;
    }
};

vector<int> solve(int n, int e, vector<int> from, vector<int> to){
    DSU d(n);
    vector<int> ans(e);
    for(int i=0; i<e; i++){
        d.join(from[i], to[i]);
        ans[i] = d.sumOfMax();
    }
    return ans;
    
}

int main(){
    int n;
    cin>>n;
    int e;
    cin >> e;
    vector<int> from(e), to(e);
    for(int i=0; i<e; i++){
        cin>> from[i] >> to[i];
    }
    vector<int> ans = solve(n, e, from, to);
    for(auto &it: ans) cout << it << " ";
    cout << endl;
}