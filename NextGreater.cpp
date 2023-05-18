/*
You have been given an array/list 'ARR' consisting of 'N'
positive integers. Your task is to return the Next Greater
Element(NGE) for every element.
The Next Greater Element for an element 'X' is the first
element on the right side of 'X' in the array 'ARR', which is
greater than 'X'. If no such element exists to the right of
then return -1.
For Example:
For the given array 'ARR'
[7, 12, 1,20]
The next greater element for 7 is 12.
The next greater element for 12 is 20.
The next greater element for 1 is 20.
There is no greater element for 20 on the right side.
So, the output is [12,20,20, -1]
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i = n-1; i >= 0; i--) {
        while(!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }
        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}