#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    vector<int> count(26, 0);
    for(auto &c: s) count[c-'A']++;
    int cnt = 0;
    for(auto &x: count) if(x & 1) cnt++;
    if(cnt > 1){
        cout << "NO SOLUTION\n";
    }else{
        int n = s.length();
        int i = 0, j = n-1;
        int idx = 0;
        while(idx < 26){
            if(count[idx] > 1){
                s[i] = s[j] = (idx + 'A');
                count[idx] -= 2;
                i++, j--;
            }else idx++;
        }
        for(int j=0; j<26; j++) if(count[j] == 1) s[i] = (j + 'A');
        cout << s << "\n";
    }
    return 0;
}
