#include<bits/stdc++.h>
using namespace std;

void wordBreak(string &s, int n, unordered_set<string> &dict, string result, vector<string> &res)
{
    for(int i = 1; i <= n; i++)
    {
        string prefix = s.substr(0, i);
        if(dict.find(prefix) != dict.end())
        {
            if(i == n)
            {
                result += prefix;
                res.push_back(result);
                return;
            }
            string remaining = s.substr(i, n-i);
            wordBreak(remaining, n-i, dict, result + prefix + " ", res);

        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    vector<string> res;
    wordBreak(s, s.size(), dict, "", res);
    return res;
}