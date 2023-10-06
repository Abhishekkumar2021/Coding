#include<bits/stdc++.h>
using namespace std;

string decodeAtIndex(string s, int k) {
    int n = s.length();
    long len = 0;
    int i = 0;
    /*
    abc3bc4cd22c1
    Final Length = 185
    k = 14
    
    
    */
    while(i<n && len < k){
        if(isdigit(s[i])){
            len *= (s[i] - '0');
        }else{
            len++;
        }
        i++;
    }

    while(i>=0){
        if(isdigit(s[i])){
            len /= (s[i]-'0');
            k %= len;
        }else{
            if(k == len || k == 0){
                string ans;
                ans.push_back(s[i]);
                return ans;
            }
            len--;
        }
        i--;
    }
    return "x";
}