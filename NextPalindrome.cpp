#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
    int len = s.length();
    for(int i=0; i<len/2; i++){
        if(s[i] != s[len-i-1]) return false;
    }
    return true;
}

bool allNine(string s){
    for(int i=0; i<s.length(); i++){
        if(s[i] != '9') return false;
    }
    return true;
}

string nextPalindrome(string s){
    // Two cases
    int n = s.length();
    if(isPalindrome(s)){
        if(allNine(s)){
            string ans = "1";
            for(int i=0; i<n-1; i++){
                ans += "0";
            }
            ans += "1";
            return ans;
        }

        int mid = n/2;
        int j = mid;
        int i = (n%2==0) ? mid-1 : mid;

        while(s[i]=='9') {
            s[i] = '0';
            s[j] = '0';
            i--;
            j++;
        }

        s[i] += 1;

        while(i>=0){
            s[j] = s[i];
            i--;
            j++;
        }

    }else{
        int mid = n/2;
        int j = mid;
        int i = (n%2==0) ? mid-1 : mid;

        while(s[i] == s[j]){
            i--;
            j++;
        }

        if(s[i] > s[j]){
            while(i>=0){
                s[j] = s[i];
                i--;
                j++;
            }
        }else{
            j = mid;
            i = (n%2==0) ? mid-1 : mid;

            while(s[i]=='9') {
                s[i] = '0';
                s[j] = '0';
                i--;
                j++;
            }

            s[i] += 1;

            while(i>=0){
                s[j] = s[i];
                i--;
                j++;
            }
        }
    }
    return s;
    
}