#include<bits/stdc++.h>
using namespace std;

/*
Approach:
1. We will use binary search.
2. We will check if mid is even or odd.
3. If mid is even then we will check if arr[mid] == arr[mid+1].
4. If arr[mid] == arr[mid+1] then we will search in the right half.
5. If arr[mid] != arr[mid+1] then we will search in the left half.
6. If mid is odd then we will check if arr[mid] == arr[mid-1].
7. If arr[mid] == arr[mid-1] then we will search in the right half.
8. If arr[mid] != arr[mid-1] then we will search in the left half.
9. We will return the element at low index.

*/
int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	// int ans = 0;
	// int n = arr.size();
	// for(int i=0; i<n; i++) ans = ans^arr[i];
	// return ans;

    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low < high)
    {
        int mid = low + (high-low)/2;
        if(mid%2 == 0)
        {
            if(arr[mid] == arr[mid+1])
            {
                low = mid+2;
            }
            else
            {
                high = mid;
            }
        }
        else
        {
            if(arr[mid] == arr[mid-1])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
    }
    return arr[low];
}