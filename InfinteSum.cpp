/*
Given an array "A" of N integers and you have also
defined the new array "B" as a concatenation of array "A"
for an infinite number of times.
For example, if the given array "A" is [1,2,3] then, infinite
array "B" is [1,2,3,1,2,3,1,2,3,.......].
Now you are given Q queries, each query consists of two
integers "L" and indexing). Your task is to
find the sum of the subarray from index "L" to "R" (both inclusive) 
in the infinite array "B" for each query.
Note :
The value of the sum
can be very large,
return the answer as
modulus 1+9+7.

Approach:
1. Find the sum of the array "A"
2. Find the number of times the array "A" is repeated
3. Find the sum of the subarray from index "L" to "R" (both inclusive) in the array "A"
4. Multiply the sum of the array "A" with the number of times the array "A" is repeated
5. Add the sum of the subarray from index "L" to "R" (both inclusive) in the array "A" to the sum of the array "A" multiplied with the number of times the array "A" is repeated
6. Return the answer as modulus 1+9+7
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    // Write your code here
    // queries contains 1 based indexing
    vector<int> ans;
    vector<long long> prefix(n+1,0);
    for(int i=1;i<=n;i++)
        prefix[i]=prefix[i-1]+arr[i-1];
    for(int i=0;i<q;i++){
        long long l=queries[i][0];
        long long r=queries[i][1];
        long long leftSum = ((l-1)/n)*prefix[n] + prefix[(l-1)%n];
        long long rightSum = ((r)/n)*prefix[n] + prefix[(r)%n];
        ans.push_back((rightSum-leftSum)%1000000007);
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3};
    int n = arr.size();
    vector<vector<long long>> queries = {{1,3},{2,5},{3,7}};
    int q = queries.size();
    vector<int> ans = sumInRanges(arr,n,queries,q);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;

}

