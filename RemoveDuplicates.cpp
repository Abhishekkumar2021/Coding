#include<bits/stdc++.h>
using namespace std;

string removeDuplicateLetters(string s) {
    vector<int> lastIndex(26, 0), vis(26, 0);
    int n = s.length();
    for(int i=0; i<n; i++){
        lastIndex[s[i]-'a'] = i;
    }

    stack<char> st;
    int i = 0;
    while(i<n){
        char c = s[i];
        // If the current character is already have veen added to the stack ===> Ignore and go ahead
        if(vis[c-'a'] == 1){
            i++;
            continue;
        } 

        // If stack is empty
        if(st.empty()){
            st.push(c);
            vis[c-'a'] = 1;
            i++;
        }else{
            char top = st.top();
            if(c < top && lastIndex[top-'a'] >= i){
                st.pop();
                vis[top-'a'] = 0;
            }
            else{
                st.push(c);
                vis[c-'a'] = 1;
                i++;
            }
        }
    }
    string ans = "";
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}