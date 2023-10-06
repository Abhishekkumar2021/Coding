#include<bits/stdc++.h>
using namespace std;

string add(string a, string b){
    string ans = "";
    int carry = 0;
    int i = a.size()-1, j = b.size()-1;
    while(i>=0 && j >=0){
        int sum = carry + (a[i]-'0') + (b[j]-'0');
        ans.push_back(sum%10 + '0');
        carry = sum/10;
    }
    while(i>=0){
        int sum = carry + (a[i]-'0');
        ans.push_back(sum%10 + '0');
        carry = sum/10;
    }
    while(j>=0){
        int sum = carry + (b[j]-'0');
        ans.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if(carry) ans.push_back(carry + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}

string multiply(string a, char ch){
    string ans = "";
    int carry = 0;
    int n = a.size();
    for(int i=n-1; i>=0; i--){
        int prod = (a[i]-'0')*(ch-'0') + carry;
        ans.push_back(prod%10 + '0');
        carry = prod/10;
    }
    if(carry) ans.push_back(carry + '0');
    reverse(ans.begin(), ans.end());
    return ans;
}

string mult(string a, string b){
    if(a == "0" || b == "0") return "0";
    int n = a.size();
    int m = b.size();

    string res(n+m, '0'); // result
    for(int i=n-1; i>=0; i--){
        int carry = 0;
        for(int j=m-1; j>=0; j--){
            int prod = (a[i]-'0')*(b[j]-'0') + (res[i+j+1]-'0') + carry;
            res[i+j+1] = prod%10 + '0';
            carry = prod/10;
        }
        res[i] += carry;
    }
    int i = 0;
    while(i < n+m && res[i] == '0') i++;
    return res.substr(i); 
}