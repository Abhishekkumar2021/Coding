#include<bits/stdc++.h>
using namespace std;

long long atMax(string &s, int k){
    long long ans = 0;
    int cnt = 0;
    int i = 0, j = 0, n = s.size();
    int freq[256] = {0};
    while(j<n){
        freq[s[j]]++;
        if(freq[s[j]] == 1) cnt++;

        while(cnt > k){
            freq[s[i]]--;
            if(freq[s[i]] == 0) cnt--;
            i++;
        }
        j++;
        ans += j-i;
    }
    return ans;
}

long long numSubstrings(string &s, int k){
    return atMax(s, k) - atMax(s, k-1);
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int testCases;
    cin>>testCases;
    for(int test = 0; test < testCases; test++){
        string s;
        int k;
        cin >> s >> k;
        cout << numSubstrings(s, k) << endl;
    }
    return 0;
}
