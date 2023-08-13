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
            string a = ans.substr(0, x/2);
            string b = ans.substr(x/2);
            q.push(a + "0" + b);
            q.push(a + "1" + b);
        }else{
            string a = ans.substr(0, x/2);
            string b = ans.substr(x/2+1);
            char ch = ans[x/2];
            q.push(a + ch + ch + b);
        }

    }
    
    return toInt(ans);
}

int main(){
    solve(10);
}