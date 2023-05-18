#include<bits/stdc++.h>
using namespace std;

bool isPermutation(string &a, string &b){
    int n = a.length();
    int m = b.length();
    if(n != m) return false;
    int count[256] = {0};
    for(int i = 0; i < n; i++){
        count[a[i]]++;
        count[b[i]]--;
    }
    for(int i = 0; i < 256; i++){
        if(count[i] != 0) return false;
    }
    return true;
}
string permutationExist(string a, string b, int n, int m)
{
    // Write your code here.
    for(int i=0; i<m-n; i++){
        string sub = b.substr(i, n);
        if(isPermutation(a, sub)) return "Yes";
    }
    return "No";
}