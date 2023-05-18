/*
You have been given a string 'S' containing only three types of characters, i.e. '(', ')' and '*'. '*' can be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
1. Any left parenthesis '(' must have a corresponding right parenthesis ')'.
2. Any right parenthesis ')' must have a corresponding left parenthesis '('.
3. Left parenthesis '(' must go before the corresponding right parenthesis ')'.
4. '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
5. An empty string is also valid.

Approach:
1. We will use two stacks, one for storing the indices of '(' and other for '*'.
2. We will iterate through the string and push the indices of '(' and '*' in their respective stacks.
3. If we encounter a ')' and the stack for '(' is not empty, we will pop the topmost index from the stack.
4. If the stack for '(' is empty, we will pop the topmost index from the stack for '*'.
5. If both the stacks are empty, we will return false.
6. After the iteration, we will check if the stack for '(' is empty or not.
7. If it is empty, we will return true.
8. If it is not empty, we will check if the stack for '*' is empty or not.
9. If it is empty, we will return false.
10. If it is not empty, we will pop the topmost index from both the stacks.
11. If the index of '(' is greater than the index of '*', we will return false.
12. If the stack for '(' is empty, we will return true.
*/

#include<bits/stdc++.h>
using namespace std;

bool checkValidString(string &s){
	// Write your code here.
    int n = s.length();
    stack<int> left;
    stack<int> star;
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            left.push(i);
        }
        else if(s[i]=='*'){
            star.push(i);
        }
        else{
            if(!left.empty()){
                left.pop();
            }
            else if(!star.empty()){
                star.pop();
            }
            else{
                return false;
            }
        }
    }
    while(!left.empty() && !star.empty()){
        if(left.top()>star.top()){
            return false;
        }
        left.pop();
        star.pop();
    }
    return left.empty();

}

