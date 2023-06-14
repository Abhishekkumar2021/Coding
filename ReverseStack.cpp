#include<bits/stdc++.h>
using namespace std;


void helper(stack<int> &st, int size){
    if(size == 0){
        while(!st.empty()){
            st.pop();
        }
        return;
    }
    
    int temp = st.top();
    helper(st, size-1);
    st.push(temp);
}
void reverseStack(stack<int> &st){
    
}