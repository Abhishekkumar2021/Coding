#include<bits/stdc++.h>
using namespace std;


/*
134

ans = 6
num = 114

*/
string divideBy2(string num){ // We assume num is divisible by 2
    string ans = "";
    int n = num.size();
    int i = 0;
    int carry = 0;
    while(i<n){
        int x = carry*10 + (num[i] - '0');
        if(x == 1){
            if(i!=0) ans.push_back('0');
            carry = 1;
        }else{
            ans.push_back(x/2+'0');
            if(x & 1) carry = 1;
            else carry = 0;
        }
        i++;
    }
    return ans;
}

bool powerOf2(string s){
    while(s != "1"){
        cout << s << endl;
        int x = s.back() - '0';
        if(x & 1) return false;
        s = divideBy2(s);
    }
    return true;
}

int main(){
    powerOf2("1210");
}