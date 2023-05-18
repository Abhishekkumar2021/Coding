#include<bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m) {
    // Write your code here. If Nth root is not integer return -1;
    double low = 1;
    double high = m;
    double eps = 1e-6;
    double mid = 0;
    while(true){
        mid = (low+high)/2;
        if(fabs(pow(mid, n)-m)<=eps){
            break;
        }
        else if(pow(mid, n)>m){
            high = mid;
        }
        else{
            low = mid;
        }
    }

    if(fabs(mid - (int)mid)<=eps){
        return (int)mid;
    }
    else{
        return -1;
    }
}