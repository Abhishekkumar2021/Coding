#include<bits/stdc++.h>
using namespace std;

int toInt(string s){
    int ans = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='1') ans = ans | (1<<i);
    }
    return ans;
}
int solve(int n) {
    if(n==1) return 1;
    n--;
    queue<string> q;
    q.push("11");
    string ans = "11";
    while(n--){
        ans = q.front();
        int x = ans.size();
        q.pop();
        
        if(x%2==0){
            string half = ans.substr(0, n/2);
            q.push(half + "0" + half);
            q.push(half + "1" + half);
        }else{
            string half = ans.substr(0, n/2-1);
            char ch = ans[n/2];
            q.push(half + to_string(ch) + to_string(ch) + half);
        }
    }
    
    return toInt(ans);
}

int main(){
    solve(10);
}