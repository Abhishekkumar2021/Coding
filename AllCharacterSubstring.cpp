#include<bits/stdc++.h>
using namespace std;

// Given a string s we have to find min length substring which contains all the characters of the string s

string shortestSubstring(string s)
{
    // Write your code here.
    int n = s.length();
    int count = 0;
    int start = 0;
    int minLen = INT_MAX;

    int freq[256] = {0};
    for(int i=0;i<n;i++){
        if(freq[s[i]]==0){
            count++;
        }
        freq[s[i]]++;
    }
    for(int i=0; i<256; i++) freq[i] = 0;
    int i=0, j=0, curr = 0;
    while(j<n)
    {
        if(freq[s[j]]==0){
            curr++;
        }
        freq[s[j]]++;
        if(curr==count){
            while(freq[s[i]]>1){
                freq[s[i]]--;
                i++;
            }
            int len = j-i+1;
            if(len<minLen){
                minLen = len;
                start = i;
            }
        }
        j++;
    }
    return s.substr(start, minLen);   
}