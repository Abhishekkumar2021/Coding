#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    // int x = 20;
    // int l = 0, r = x;
    // while(l<=r){
    //     int mid = (l+r)/2;
    //     if(mid*mid <= x){
    //         l = mid + 1;
    //     }else{
    //         r = mid - 1;
    //     }
    // }

    int arr[] = {1, 2, 5, 4, 3, 2, 1};
    int l = 0, r = 6;
    while(l <= r){
        int mid = (l+r)/2;
        if((mid == 0 && arr[mid+1] < arr[mid]) || (mid == 6 && arr[mid-1] < arr[mid])){
            return mid;
        }
    }
    return 0;
}