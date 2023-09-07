#include<bits/stdc++.h>
using namespace std;

void arrange(vector<int> &arr) {
    // 0, 2, 1, 3
    // arr[i] = arr[i] + (arr[arr[i]]%n)*n
    // 0 + 0, 2 + 1*4, 1 + 2*4, 3 + 3*4
    // 0, 1, 2, 3
    int n = arr.size();
    for(int i=0; i<n; i++) arr[i] += (arr[arr[i]]%n)*n;
    for(int i=0; i<n; i++) arr[i] /= n; 
}