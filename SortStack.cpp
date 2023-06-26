#include<bits/stdc++.h>
using namespace std;

void insertCorrect(stack<int> &stack, int temp){
    if(stack.size() == 0 || stack.top() <= temp){
        stack.push(temp);
        return;
    }
    int val = stack.top();
    stack.pop();
    insertCorrect(stack, temp);
    stack.push(val);
}

void sortStack(stack<int> &stack)
{
	if(stack.size()==0) return;
    int temp = stack.top();
    stack.pop();
    sortStack(stack);

    // Put at correct position
    insertCorrect(stack, temp);
}