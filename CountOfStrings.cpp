/*
Problem Statement
Ninja has a binary string 'S' of length 'N'. Initially, all the characters in a string are '1', i.e.
S[i] = '1' for each 1 <= 'i' <= 'N'.
An operation is defined as choosing a number between 1 to 4, and doing the following steps accordingly.
1. If the chosen number is 1, then flip all the characters in string.
2. If the chosen number is 2, then flip all the characters at odd indexes.
3. If the chosen number is 3, then flip all the characters at even indexes.
4. If the chosen number is 4, then flip all the characters at (3k + 1) indexes.
You need to find out that after performing operations exactly 'M' number of times, how many distinct final strings can be there.

Hints:
1. You can use the concept of the cycle of length 4.
2. You can use the concept of the cycle of length 2.
3. You can use the concept of the cycle of length 1.

Input Format:
The first line contains an integer 'T' which denotes the number of test cases or queries to be run. Then the test cases follow.
The first line of each test case contains two space-separated integers 'N' and 'M' denoting the length of the string and the number of operations to be performed respectively.

Output Format:
For each test case, print a single line containing one integer denoting the number of distinct final strings that can be there after performing exactly 'M' operations.

Effect:
1 + 1 => Nothing
2 + 2 => Nothing
3 + 3 => Nothing
4 + 4 => Nothing
1 + 2 => 3
2 + 1 => 3
1 + 3 => 2
3 + 1 => 2
2 + 3 => 1
3 + 2 => 1

*/
#include<bits/stdc++.h>
using namespace std;

int countOfStrings(int n, int m)
{
    // Write your code here.
    if(m == 0){
        return 1;
    }
    if(n == 1){
        return 2;
    }
    
    
    return 8;
}