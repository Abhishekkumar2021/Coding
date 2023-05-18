/*
Assume you initially have an empty array say 'ARR.
You need to return the updated array provided that some 'Q' number of
queries were performed on this array.
The queries are of two types:
1. 1 'VAL',
for this type of query, you need to insert the
integer 'VAL' to the end of the array.
2. 2 'VAL',
for this type of query, you need to take the
bitwise XOR of all the elements of the array with 'VAL' i.e
each element of the array 'ARR' will be updated as 'ARR[i]' —
A denotes the bitwise XOR operation)
'ARR[i]
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> xorQuery(vector<vector<int>> &q)
{
	// Write your code here
	vector<int> ans;
	int n = q.size();
    int arr[n];
    int x = 0;
    for(int i=0;i<n;i++)
    {
        if(q[i][0]==1)
        {
            arr[x] = q[i][1];
            x++;
        }
        else
        {
            int val = q[i][1];
            for(int j=0;j<x;j++)
            {
                arr[j] = arr[j]^val;
            }
        }
    }
    for(int i=0;i<x;i++)
    {
        ans.push_back(arr[i]);
    }
    return ans;
}