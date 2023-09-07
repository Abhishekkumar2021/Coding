#include<bits/stdc++.h>
using namespace std;

bool rabinKarp(string text, string pat){
    int n = text.length();
    int m = pat.length();

    // Check if starting is matching
    if(text.substr(0, m) == pat) return 0;

    int textHash = 0;
    int patHash = 0;

    int prime = 101;
    int setLength = 256;

    int i = 0, j = 0;
    while(i<m){
        textHash = (setLength*textHash + text[i])%prime; 
        patHash = (setLength*patHash + pat[i])%prime; 
        i++;
        j++;
    }

    int power = 1;
    for(int i=1; i<=m-1; i++) power = (power*setLength)%prime;
    while(i<n){
        // remove previous element
        textHash = textHash - power*text[i-m];

        // add current element
        textHash = (textHash*setLength + text[i] + prime)%prime;

        // Check for hash 
        if(textHash == patHash){
            // Check for equality
            if(text.substr(i-m, m) == pat) return i-m;
        }
        i++;
    }
    return -1;
}