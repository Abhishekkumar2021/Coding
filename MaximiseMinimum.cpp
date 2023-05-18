/*
You are given two positive integers, 'X' and 'Y', 'X' <= 'Y', and an array 'A' of size 'N'. You can perform the following operation any number of times (possibly zero): Choose two distinct indices i, j (1 ≤ i, j ≤ 'N'). Make 'A[i]' = 'A[i]' + 'X' and 'A[j]' = 'A[j]' - 'Y'. You have to maximise the value of min('A[0]', 'A[1]'.. 'A[N-1]') after all the operations. Return a number 'C' denoting the maximum value of min('A[0]', 'A[1]'.. 'A[N-1]') after all the operations.
Note: Assume 0-based indexing.
For Example:
Let 'N' = 3, 'X' = 2, 'Y' = 2, and 'A' = [1, 5, 9].
'A'
=
[3, 5, 7].s
=
[5, 5,
In the first operation, we will choose index {0, 2} and In the second operation, we will choose index {0, 2} and 'A' 5].
The minimum value of array 'A' is 5. So, the answer is 5.

*/


#include <bits/stdc++.h>
using namespace std;

int maximumAmongMinimum(int n, int x, int y, vector<int>&a){
	// Write your code here.
    int min = a[0];
    for(int i=1;i<n;i++){
        if(a[i]<min){
            min = a[i];
        }
    }
    int max = min;
    for(int i=0;i<n;i++){
        a[i] = a[i] - min;
    }
    int i=0,j=n-1;
    while(i<j){
        a[i] = a[i] + x;
        a[j] = a[j] - y;
        i++;
        j--;
    }
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}

