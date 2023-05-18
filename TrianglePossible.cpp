/*
You are given an array of integers A, of size N. Return 1 if it is possible to make a triangle of non-zero area using 3 of these sides. Return 0 otherwise.
Example Input
Input :
A = [2, 1, 8]
Output :
0

Approach:
1. Sort the array
2. Check if the sum of any two sides is greater than the third side
3. If yes, return 1
4. Else return 0

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-2;i++)
    {
        if(a[i]+a[i+1]>a[i+2])
            return 1;
    }
    return 0;
}