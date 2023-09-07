#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int left = 0, right = n-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid] == k) return mid;

        // Before checking which part is sorted we have to check if elements at low, mid and high are all equal if they are then that will be a problem 
        if(arr[left] == arr[mid] && arr[mid]==arr[right]){
            // trim down
            left++;
            right--;
            continue;
        }
        
        
        // Check which part is sorted
        if(arr[left] <= arr[mid]){
            if(arr[left] <= k && k <= arr[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }else{
            if(arr[mid] <= k && k <= arr[right]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
    }
    return -1;
}