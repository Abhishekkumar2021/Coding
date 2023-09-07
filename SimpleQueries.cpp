/*
Problem Description
 
 

You are given an array A having N integers.

You have to perform the following steps in a given order.

1) generate all subarrays of A.

2) take the maximum element from each subarray of A and insert it into a new array G.

3) replace every element of G with the product of their divisors mod 1e9 + 7.

4) sort G in descending order

You now need to perform Q queries

In each query, you are given an integer K, where you have to find the Kth element in G.

NOTE : Your solution will run on multiple test cases so do clear global variables after using them.



Problem Constraints
1 <= N <= 1e5

1 <= A[i] <= 1e5

1 <= Q <= 1e5

1 <= k <= (N * (N + 1))/2 



Input Format
The first argument given is an Array A, having N integers.

The second argument given is an Array B, where B[i] is the ith query.



Output Format
Return an Array X, where X[i] will have the answer for the ith query.



Example Input
Input 1:

A = [1, 2, 4]
B = [1, 2, 3, 4, 5, 6]
Input 2:

A = [1, 3]
B = [1]


Example Output
Output 1:

[8, 8, 8, 2, 2, 1]
Output 2:

[3]

Example Explanation
Explanation 1:

subarrays of A    maximum element
[1]                 1
[1, 2]              2
[1, 2, 4]           4
[2]                 2
[2, 4]              4
[4]                 4
original
G = [1, 2, 4, 2, 4, 4]

after changing every element of G with product of their divisors
G = [1, 2, 8, 2, 8, 8]

after sorting G in descending order
G = [8, 8, 8, 2, 2, 1]

Explanation 2:

Just perform given query
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr, vector<int> &query) {
    int maxSize = 1e5;
    int mod = 1e9 + 7;
    vector<long long> prod(maxSize+1, 1);
    for(int i=2; i<=maxSize; i++){
        for(int j=i; j<=maxSize; j+=i){
            prod[j] = (prod[j]*i)%mod;
        }
    }
    int n = arr.size();
    stack<int> s;
    vector<int> pre(n), next(n);
    for(int i=0; i<n; i++){
        while(!s.empty() && arr[s.top()] <= arr[i]) s.pop();
        if(s.empty()) pre[i] = -1;
        else pre[i] = s.top();
        s.push(i);
    }
    
    while(!s.empty()) s.pop();

    for(int i=n-1; i>=0; i--){
        while(!s.empty() && arr[s.top()] < arr[i]) s.pop();
        if(s.empty()) next[i] = n;
        else next[i] = s.top();
        s.push(i);
    }

    // {prodctOfDivisors, count}
    vector<pair<int, long long>> g;
    for(int i=0; i<n; i++){
        g.push_back({prod[arr[i]], (i - pre[i])*(next[i] - i)});
    }

    sort(g.begin(), g.end(), greater<pair<int, long long>>());

    // Prefix sum
    for(int i=1; i<n; i++) g[i].second += g[i-1].second;
    vector<long long> binary(n);
    for(int i=0; i<n; i++) binary[i] = g[i].second;

    vector<int> ans;
    int q = query.size();
    for(int i=0; i<q; i++){
        int idx = lower_bound(binary.begin(), binary.end(), (long long)query[i]) - binary.begin();
        ans.push_back(g[idx].first);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    int q;
    cin>>q;
    vector<int> query(q);
    for(int i=0; i<q; i++) cin>>query[i];
    vector<int> ans = solve(arr, query);
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;
}