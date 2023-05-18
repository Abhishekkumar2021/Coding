/*
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of the smallest valid substring ( ) is 2.

Example 1:

Input: S = "(()("
Output: 2
Explanation: The longest valid 
substring is "()". Length = 2.
Example 2:

Input: S = "()(())("
Output: 6
Explanation: The longest valid 
substring is "()(())". Length = 6.

Your Task:  
You dont need to read input or print anything. Complete the function findMaxLen() which takes S as input parameter and returns the maxlength.


Expected Time Complexity:O(n)
Expected Auxiliary Space: O(1)   


Constraints:
1 <= |S| <= 105

Approach:
1. We will use a stack to store the indices of the opening brackets.
2. We will also keep a variable to store the length of the longest valid substring.
3. We will traverse the string from left to right.
4. If we encounter an opening bracket, we will push its index in the stack.
5. If we encounter a closing bracket, we will check if the stack is empty or not.
6. If the stack is empty, we will update the starting index of the current valid substring to the current index.
7. If the stack is not empty, we will pop the top element from the stack.
8. If the stack is empty after popping, we will update the length of the longest valid substring to the maximum of the current length and the current index minus the starting index.
9. If the stack is not empty after popping, we will update the length of the longest valid substring to the maximum of the current length and the current index minus the top element of the stack.
10. We will return the length of the longest valid substring.

*/

#include<bits/stdc++.h>
using namespace std;

int findMaxLen(string s) {
    int n = s.length();
    stack<int> st;
    int start = 0;
    int len = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            st.push(i);
        }
        else {
            if(st.empty()) {
                start = i + 1;
            }
            else {
                st.pop();
                if(st.empty()) {
                    len = max(len, i - start + 1);
                }
                else {
                    len = max(len, i - st.top());
                }
            }
        }
    }
    return len;
}