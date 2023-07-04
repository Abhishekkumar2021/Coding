#include<bits/stdc++.h>
using namespace std;


vector<int> lps(string s){
    int n = s.size();
    vector<int> lps(n,0);
    int i=0,j=1;
    while(j<n){
        /*
            Two cases
            1. If s[i] == s[j] then lps[j] = i+1 and i++,j++
            2. If s[i] != s[j] then
                if i == 0 then lps[j] = 0 and j++
                else i = lps[i-1]

        */
       if(s[i] == s[j]){
           lps[j] = i+1;
           i++;
           j++;
       }
       else{
           if(i == 0){
               lps[j] = 0;
               j++;
           }
           else{
               i = lps[i-1];
           }
       }
    }
    return lps;
}

int main(){
    string s;
    cin>>s;
    vector<int> lps_arr = lps(s);
    for(int i=0;i<lps_arr.size();i++){
        cout<<lps_arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}