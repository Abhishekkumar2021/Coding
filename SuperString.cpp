#include <bits/stdc++.h>
using namespace std;

// Input: words = ["catg","ctaagt","gcta","ttca","atgcatc"]
// Output: "gctaagttcatgcatc"

string merge(string &a, string &b)
{
    int n = a.size();
    int m = b.size();
    int mini = min(n, m);
    int ans = 0;
    for (int i = 1; i <= mini; i++){
        if (a.substr(n - i) == b.substr(0, i))
            ans = i;
    }
    return a + b.substr(ans);
}

void superString(vector<string> &words, int idx, string &ans, int &mini)
{
    if(idx == words.size()){
        string temp = "";
        for(string s: words){
            temp = merge(temp, s);
        }
        if(temp.size() < mini){
            mini = temp.size();
            ans = temp;
        }
        return;
    }

    // Try to add the current word in the ans
    for(int i=idx; i<words.size(); i++){
        swap(words[i], words[idx]);
        superString(words, idx+1, ans, mini);
        swap(words[i], words[idx]);
    }
}

string shortestSuperstring(vector<string>& words) {
    string ans = "";
    int mini = INT_MAX;
    superString(words, 0, ans, mini);
    return ans;
}