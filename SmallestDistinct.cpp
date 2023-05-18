#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers, find the length of the smallest subarray in it which contains all the distinct elements of the given array.
*/

vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k){
    // Write your code here.

    int n = arr.size();
    int count = 0;
    int start = 0;
    int end = 0;
    int minLen = INT_MAX;

    map<int, int> freq;
    
    int i = 0, j = 0;
    while(j<n){
        if(freq[arr[j]]==0){
            count++;
        }
        freq[arr[j]]++;
        if(count==k){
            while(freq[arr[i]]>1){
                freq[arr[i]]--;
                i++;
            }
            int len = j-i+1;
            if(len<minLen){
                minLen = len;
                start = i;
                end = j;
            }
        }
        j++;
    }

    // return start and end index of the smallest subarray
    return {start, end};
}