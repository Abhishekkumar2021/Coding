#include<bits/stdc++.h>
using namespace std;

string encode(string &s, vector<int> &mapping){
    string ans = "";
    int n = s.size();
    for(int i=0; i<n; i++){
        char c = s[i];
        char mapped = mapping[c-'A'] + '0';
        ans += mapped;
    }
    return ans;
}

int main(){
    int testcase;
    cin>>testcase;
    for(int t=1; t<=testcase; t++){
        vector<int> mapping(26);
        for(int i=0; i<26; i++){
            cin>>mapping[i];
        }
        int n;
        cin>>n;
        int flag = 0;
        unordered_map<string, string> mp;
        while(n--){
            string s;
            cin>>s;
            string encoded = encode(s, mapping);
            if(mp.find(encoded) != mp.end() && mp[encoded] != s){
                flag = 1;
                break;
            }else{
                mp.insert({encoded, s});
            }
        }
        if(flag == 1){
            cout<<"Case #"<<t<<": "<<"YES"<<endl;
        }else{
            cout<<"Case #"<<t<<": "<<"NO"<<endl;
        }

    }
}