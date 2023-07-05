#include<bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'; 
}

string reverseVowels(string s) {
    int start = 0;
    int end = s.length() - 1;
    while(start < end){
        // Three cases
        // 1. Both are vowels => swap and increment start and decrement end
        // 2. Only start is vowel => decrement end
        // 3. Only end is vowel => increment start
        if(isVowel(s[start]) && isVowel(s[end])) {
            swap(s[start], s[end]);
            start++;
            end--;
        } else if(isVowel(s[start])) {
            end--;
        } else if(isVowel(s[end])) {
            start++;
        } else {
            start++;
            end--;
        }
    }
    return s;
}