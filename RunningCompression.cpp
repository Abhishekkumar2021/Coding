#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    string ans = "";
    int n = chars.size();

    int curr = 0;
    while(curr < n) {
        int count = 1;
        char ch = chars[curr];
        curr++;
        while(curr < n && chars[curr] == ch) {
            count++;
            curr++;
        }
        ans += ch;
        if(count > 1) {
            ans += to_string(count);
        }
    }

    int m = ans.size();
    for(int i = 0; i < m; i++) {
        chars[i] = ans[i];
    }

    return m;      
}