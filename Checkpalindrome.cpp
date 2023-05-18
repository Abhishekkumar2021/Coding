#include<bits/stdc++.h>
using namespace std;

/**
 * The function checks if a given string is a palindrome after removing spaces, special characters, and
 * ignoring case.
 * 
 * @param s The input string that needs to be checked for palindrome.
 * 
 * @return The function `checkPalindrome` returns a boolean value - `true` if the input string `s` is a
 * palindrome (reads the same forwards and backwards), and `false` otherwise.
 */
bool checkPalindrome(string s)
{
    // Write your code here.
    int i=0, j=0, n = s.size();
    //remove spaces and special characters
    while(j<n){
        if(s[j] >= 'a' && s[j] <= 'z'){
            s[i] = s[j];
            i++;
        }
        else if(s[j] >= 'A' && s[j] <= 'Z'){
            s[i] = s[j] + 32;
            i++;
        }
        else if(s[j] >= '0' && s[j] <= '9'){
            s[i] = s[j];
            i++;
        }
        j++;
    }
    s = s.substr(0, i);
    // cout<<s<<endl;
    //check palindrome
    i = 0;
    j = s.size()-1;
    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (checkPalindrome(s))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}