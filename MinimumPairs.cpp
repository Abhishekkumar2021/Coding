/*
You are given an integer 'NUM'. Your task is to find out
two numbers 'FIRST' and 'SECOND' such that their
product is equal to either 'NUM' + 1 or 'NUM' + 2 and their
absolute difference is the minimum between all such
pairs.

Sample Input 1:
1
10
Sample Output 1:
Explanation For Sample Input 1:
'NUM' + 1 is equal
would be 1 and 11,
the answer will be
answer is 3 and 4.
to 11 for which the answer
for 'NUM' + 2, which is 12
3 and 4. Hence the better

Approach:
*/
#include<bits/stdc++.h>
using namespace std;

vector< int > closestDivisors(int num) {
    // Write your code here
    vector < int > ans;
    int a = num + 1;
    int b = num + 2;
    int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    for(int i = 1; i <= sqrt(a); i++) {
        if(a % i == 0) {
            a1 = i;
            a2 = a / i;
        }
    }
    for(int i = 1; i <= sqrt(b); i++) {
        if(b % i == 0) {
            b1 = i;
            b2 = b / i;
        }
    }
    if(abs(a1 - a2) < abs(b1 - b2)) {
        ans.push_back(a1);
        ans.push_back(a2);
    } else {
        ans.push_back(b1);
        ans.push_back(b2);
    }
    
}