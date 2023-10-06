#include<bits/stdc++.h>
using namespace std;

int min_computers(string s,int n){
    if(n == 1){
        if(s[0] == '.')
            return 0;
        return -1;
    }
    if((s[0] == 's' && s[1] == 's') || (s[n-2] == 's' && s[n-1] == 's'))
        return -1;
    int i,cnt = 0;
    for(i=1; i<n-1; i++){
        if(s[i-1] == 's' && s[i] == 's' && s[i+1] == 's')
            return -1;
    }
    bool c[n] = {false};
    i = 0;
    while(i<n){
        if(s[i] == 's'){
            int left = i-1;
            if(left>=0){
                if(c[left]){
                    i++;
                }
                else{
                    if(i+1<n){
                        if(s[i+1] == 's'){
                            cnt++;
                            c[i-1] = true;
                            i++;
                        }
                        else{
                            i++;
                            if(i<n){
                                cnt++;
                                c[i] = true;
                            }
                        }
                    }
                    else{
                        cnt++;
                        c[i-1] = true;
                        i++;
                    }
                }
            }
            else{
                i++;
                if(i<n){
                    cnt++;
                    c[i] = true;
                }
            }
        }
        else
            i++;
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int testCases;
    cin>>testCases;
    for(int test = 0; test < testCases; test++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        cout<<min_computers(s,n)<<"\n";
    }
    return 0;
}