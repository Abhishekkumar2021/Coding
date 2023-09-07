#include<bits/stdc++.h>
using namespace std;

int pivot(vector<int> &arr){
    int n = arr.size();
    int left = 0, right = n-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        // This is the case when array is not bitonic
        if(mid == 0 or mid == n-1) return mid;
        // case when mid is peak element
        if(arr[mid] > arr[mid-1] and arr[mid] > arr[mid+1]) return mid;
        if(arr[mid] < arr[mid+1]) left = mid + 1;
        else right = mid - 1;
    }
}

int bitonicSearch(vector<int> &arr, int key){
    /*
    4x4
    4 => 1
    3 => 4
    2 => 9
    1 => 16
    */
    int n = arr.size();
    int idx = pivot(arr);
    int left = 0, right = idx;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) left = mid+1;
        else right = mid - 1;
    }

    left = idx + 1, right = n-1;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) right = mid-1;
        else left = mid + 1;
    }

    return -1;
}