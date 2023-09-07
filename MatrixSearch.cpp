#include<bits/stdc++.h>
using namespace std;

int searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size();
    int m = A[0].size();
    int left = 0, right = m*n - 1;
    while(left <= right){
        int mid = left +(right-left)/2;
        int row = mid/m;
        int col = mid/m;
        if(A[row][col] == B) return 1;
        if(A[row][col] < B) left = mid + 1;
        else right = mid - 1;
    }
    return 0;
    binary_search(A.begin(), A.end(), B);
}

/*
[
    [1],
    [2],
    [3],
    [4],
    [5]
]

n = 5
m = 1
mid = 2



*/