#include<bits/stdc++.h>
using namespace std;    

/*
Approach:
1. We will use the array as a hash table.
2. We will mark the elements which are present in the array.
3. We will ignore the elements which are not in the range of 1 to n.
4. We will mark the elements which are present in the array by making the element at that index negative.
5. We will traverse the array and return the first positive element.
6. If we don't find any positive element then we will return n+1.
*/

int firstMissing(int arr[], int n)
{
    // Write your code here.

    // Marking the elements which are not in the range of 1 to n.
    for(int i=0; i<n; i++)
    {
        if(arr[i] <= 0 || arr[i] > n)
        {
            arr[i] = n+1;
        }
    }

    // Marking the elements which are present in the array by making the element at that index negative.
    for(int i=0; i<n; i++)
    {
        int index = abs(arr[i]) - 1;
        if(index < n && arr[index] > 0)
        {
            arr[index] = -arr[index];
        }
    }

    // Traversing the array and returning the first positive element.
    for(int i=0; i<n; i++)
    {
        if(arr[i] > 0)
        {
            return i+1;
        }
    }

    // If we don't find any positive element then we will return n+1.
    return n+1;
    
}