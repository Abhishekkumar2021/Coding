#include <bits/stdc++.h> 
using namespace std;

/*
Input:
3
4
1 3 1 4
6
1 3 1 4 3 1
3
3 1 3

Output:
3
4
0

Explanation:
The first test case is already explained in the problem statement.
The second test case, the given array is: [1 3 1 4 3 1] and the longest mountain would be of length: 4 i.e. 1 4 3 1.
The third test case, the given array is: [3 1 3] and the longest mountain would be of length: 0 since there is no increasing, peak and decreasing subarray. 
*/

int longestMountain(int *arr, int n)
{
    // Write your code here.
    int i = 0;
    int j = 0;
    int max = 0;
    // Correct the code
    while (i < n)
    {
        j = i;
        while (j + 1 < n && arr[j] < arr[j + 1])
        {
            j++;
        }
        if (j == i)
        {
            i++;
            continue;
        }
        int k = j;
        while (k + 1 < n && arr[k] > arr[k + 1])
        {
            k++;
        }
        if (k == j)
        {
            i = j + 1;
            continue;
        }
        if (k - i + 1 > max)
        {
            max = k - i + 1;
        }
        i = k;
    }
}