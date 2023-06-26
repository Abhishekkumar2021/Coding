#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        while(j<n){
            // is_uppercase
            if(s[j] >= 'A' && s[j] <= 'Z'){
                s[i] = s[j] - 'A' + 'a';
                i++;
                j++;
            }else if(s[j] >= 'a' && s[j] <= 'z'){
                s[i] = s[j];
                i++;
                j++;
            }else if(s[j] >= '0' && s[j] <= '9'){
                s[i] = s[j];
                i++;
                j++;
            }else{
                j++;
            }
            
        }

        s = s.substr(0, i);
        string temp = s;
        reverse(temp.begin(), temp.end());
        return temp == s;
    }
};