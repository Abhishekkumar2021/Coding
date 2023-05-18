#include<bits/stdc++.h>
using namespace std;

double root(double n){
    double l = 0, r = n;
    double mid;
    while(r - l > 0.0000000001){
        mid = (l + r) / 2;
        if(mid * mid < n){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return mid;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        double n;
        cin>>n;
        cout<<root(n)<<endl;
    }
}