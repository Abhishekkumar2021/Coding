#include<bits/stdc++.h>
using namespace std;

// Assuming no characters are repeated
int sortedRank(string s){
    const int mod = 1000003;
    int n = s.size();
    int ans = 1;
    string st = s;
    sort(st.begin(), st.end(), [](char &a, char &b){
        return a <= b;
    });
    vector<long long> fact(n+1, 1);
    for(int i=2; i<=n; i++) fact[i] = (i*fact[i-1])%mod;
    for(int i = 0; i < n; i++){
        // Find number of elements smaller than this character
        int small = lower_bound(st.begin(), st.end(), s[i]) - st.begin();
        int large = st.length() - 1;
        ans = (ans + small*fact[large])%mod;
        st.erase(small, 1);
    }
    return ans;
}

int main(){
    cout << sortedRank("acb");
}