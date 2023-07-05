#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    int n = s.length();
    // Remove leading spaces
    int i = 0;
    while (i < n && s[i] == ' ') i++;

    // Remove trailing spaces
    int j = n - 1;
    while (j >= 0 && s[j] == ' ') j--;

    // Reduce multiple spaces to single one
    int k = 0;
    bool space = false;
    while (i <= j) {
        if (s[i] == ' ') {
            if (!space) {
                s[k++] = s[i];
                space = true;
            }
        } else {
            s[k++] = s[i];
            space = false;
        }
        i++;
    }

    // Remove spaces from the end
    s = s.substr(0, k);

    // Reverse word by word
    int start = 0;
    int end = 0;
    while (end < s.length()) {
        while (end < s.length() && s[end] != ' ') end++;
        reverse(s.begin() + start, s.begin() + end);
        start = end + 1;
        end++;
    }

    // Reverse the whole string
    reverse(s.begin(), s.end());
    return s;
}