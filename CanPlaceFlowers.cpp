#include<bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& arr, int n) {
    // Is all the elements are 0
    int m = arr.size();
    int startingZeros = 0;
    int endingZeros = 0;
    int start = 0;
    int end = m-1;
    while(start < m && arr[start] == 0) {
        startingZeros++;
        start++;
    }
    // If all the elements are 0
    if(startingZeros == m) {
        return (m+1)/2 >= n;
    }
    while(end >= 0 && arr[end] == 0) {
        endingZeros++;
        end--;
    }
    n -= (startingZeros/2 + endingZeros/2);
    int count = 0;
    for(int i = start; i <= end; i++) {
        if(arr[i] == 0) {
            count++;
        } else {
            n -= (count-1)/2;
            count = 0;
        }
    }
    
    return n <= 0;
}