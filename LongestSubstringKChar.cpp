/*
You are given a string 'S' of length 'N' consisting of
lowercase English alphabet letters. You are also given a
positive integer 'K'.
Now, a substring of this string is good if it contains at
most 'K' distinct characters. A string 'X' is a substring of
string 'Y' if it can be obtained by deletion of several
continuous elements(possibly zero) from the beginning
and the end from the string 'Y'.
Your task is to return the maximum size of any good
substring of the string 'S'.
*/

#include<bits/stdc++.h>
using namespace std;

int getLengthofLongestSubstring(string s, int k) {
    // Write your code here.
    int freq[26] = {0};
    int i = 0, j = 0, ans = 0;
    int count = 0;
    int n = s.size();
    while(j < n){
        if(freq[s[j] - 'a'] == 0)
            count++;
        freq[s[j] - 'a']++;
        if(count <= k){
            ans = max(ans, j - i + 1);
        }
        while(count > k){
            freq[s[i] - 'a']--;
            if(freq[s[i] - 'a'] == 0)
                count--;
            i++;
        }
        j++;
    } 
    return ans;  
}