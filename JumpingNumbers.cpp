#include<bits/stdc++.h>
using namespace std;

/*
A number is called as a Jumping Number if all adjacent digits in it differ by 1.
All single digit numbers are considered as Jumping Numbers. For example 7, 8987 and 4343456 are Jumping numbers but 796 and 89098 are not.

Given a positive number x, print all Jumping Numbers smaller than or equal to x.
The numbers can be printed in any order.

Example:
Input: x = 20
Output: 0 1 2 3 4 5 6 7 8 9 10 12

Approach:
1. Naive Approach: Generate all the numbers from 0 to x and check if they are jumping numbers or not.
Time Complexity: O(x) where x is the given number.
2. Efficient Approach: Use BFS to generate all the jumping numbers.
- Start from 0 and generate all the jumping numbers using BFS traversal.
- Maintain a queue to store the jumping numbers.
- Push 0 to the queue.
- Run a loop until the queue is empty.
- Pop the front element of the queue and append all the adjacent digits to it (if the digit is 0 or 9 then only one adjacent digit will be added).
- If the popped number is smaller than or equal to x, then print it.
- Repeat the above steps until the queue is empty.
*/


void bfs(int x, int n){
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int num = q.front();
        q.pop();
        if(num <= n){
            int last_digit = num%10;
            if(last_digit == 0){
                q.push(num*10 + last_digit + 1);
            }
            else if(last_digit == 9){
                q.push(num*10 + last_digit - 1);
            }
            else{
                q.push(num*10 + last_digit - 1);
                q.push(num*10 + last_digit + 1);
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    cout<<"0 ";
    for(int i=1;i<=9;i++){
        bfs(i, n);
    }
    return 0;
}