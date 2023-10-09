#include <bits/stdc++.h>
using namespace std;

vector<int> construct(int n, int c, int m)      
{
    if(n==1) return vector<int>(1, m);

    if(c-1 >= n-2 and c-1 <= (n*(n-1))/2 - 1)
    {
        vector<int> arr = construct(n-1, c-1, m+1);
        arr.insert(arr.begin(), m);
        return arr;
    }

    int x = c - (n*(n-1))/2 + 1;
    vector<int> arr = construct(n-1, c-x, m+1);
    reverse(arr.begin(), arr.begin() + x - 1);
    arr.insert(arr.begin() + x - 1, m);
    return arr;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>>n>>c;
        if(c<n-1 or c>(n*(n+1))/2 -1) 
        {
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        vector<int> ans = construct(n, c, 1);
        for(int i=0; i<n; i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }
}