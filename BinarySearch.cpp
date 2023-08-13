#include<bits/stdc++.h>
using namespace std;

int floor(int arr[], int n, int x){
    // We have to find out index of an element which is less than or equal to x
    int l = 0, r = n-1;
    int ans = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid] <= x){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    return ans;
}

int ceil(int arr[], int n, int x){
    // We have to find out index of an element which is greater than or equal to x
    int l = 0, r = n-1;
    int ans = -1;
    while(l<=r){
        int mid = l + (r-l)/2;
        if(arr[mid] >= x){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.
	sort(arr,arr+n);
    int f = floor(arr,n,x);
    int c = ceil(arr,n,x);
    if(f == -1) return {-1,arr[c]};
    if(c == -1) return {arr[f],-1};
    return {arr[f],arr[c]};
}