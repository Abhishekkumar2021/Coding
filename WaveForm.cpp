#include<bits/stdc++.h>
using namespace std;

void waveForm(vector<int> &arr){
    // Sort the array
    sort(arr.begin(), arr.end());

    // Swap the adjacent elements
    for(int i=0; i<arr.size()-1; i+=2){
        swap(arr[i], arr[i+1]);
    }
}