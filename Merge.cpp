#include<bits/stdc++.h>
using namespace std;

// Merge two arrays into first array
void merge(vector<int> &a, vector<int> &b){
    int n = a.size(), m = b.size();
    int i = n-1, j = m-1, k = n+m-1;

    // First fill the remaining elements of a with 0
    for(int i=0; i<m; i++) a.push_back(0);

    while(i >= 0 && j >= 0){
        if(a[i] > b[j]){
            a[k] = a[i];
            i--;
        }
        else{
            a[k] = b[j];
            j--;
        }
        k--;
    }
    // If elements of a are still remaining then no need to do anything as they are already in their correct position

    // If elements of b are still remaining
    while(j >= 0){
        a[k] = b[j];
        j--;
        k--;
    }

}