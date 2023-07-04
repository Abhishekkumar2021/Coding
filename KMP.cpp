#include<bits/stdc++.h>
using namespace std;

bool isExist(string text, string pat){
    /*
        This function returns true if pat is a substring of text
        else it returns false.
        Exaplanation of algorithm:
        1. First we will create a lps array for the pattern.
        2. Then we will traverse the text and pattern simultaneously.
        3. If text[i] == pat[j] then i++,j++
        4. If text[i] != pat[j] then
            if j == 0 then i++
            else j = lps[j-1]

    */
    int n = text.size();
    int m = pat.size();
    vector<int> lps(m,0);
    int i=0,j=1;
    while(j<m){
        if(pat[i] == pat[j]){
            lps[j] = i+1;
            i++;
            j++;
        }
        else{
            if(i == 0){
                lps[j] = 0;
                j++;
            }
            else{
                i = lps[i-1];
            }
        }
    }

    i=0,j=0;
    while(i<n){
        if(text[i] == pat[j]){
            i++;
            j++;
        }
        else{
            if(j == 0){
                i++;
            }
            else{
                j = lps[j-1];
            }
        }
        if(j == m){
            return true;
        }
    }
    return false;
}