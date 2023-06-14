#include <bits/stdc++.h>
using namespace std;

int LPSS(string &s, int i, int j)
{
    if (i == j)
        return 1;
    if (i + 1 == j)
        return s[i] == s[j] ? 2 : 1;
    if (s[i] == s[j])
        return 2 + LPSS(s, i + 1, j - 1);
    else
        return max(LPSS(s, i + 1, j), LPSS(s, i, j - 1));
}

string LPS(string &s){
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // Base case
    for(int i=0; i<n; i++){
        dp[i][i] = true;
        if(i==n-1) break;
        dp[i][i+1] = s[i] == s[i+1];
    }

    // Fill the table
    for(int i=n-3; i>=0; i--){
        for(int j=i+2; j<n; j++){
            dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
        }
    }

    // Find the max length
    int maxLen = 0;
    int start = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(dp[i][j] && j-i+1 > maxLen){
                maxLen = j-i+1;
                start = i;
            }
        }
    }

    return s.substr(start, maxLen);
}

int main(){
    string s = "abccbc";
    cout << LPSS(s, 0, s.length() - 1) << endl;
    return 0;
}