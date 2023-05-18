#include <bits/stdc++.h> 
using namespace std;

/*
You are given three strings, 'A', 'B', and 'C', each of length 'N' consisting of lower case alphabets. The difference between the three strings is defined as ΣA[i] – B[i]| + |A[i] – C[i]| where |A[i] - B[i]| and |A[i] – C[i]| are the absolute differences between ASCII values of the characters at the position i in strings 'A', 'B' and 'A','C' respectively. You are allowed to rotate the string 'A' cyclically. There are a total of 'N' possible rotations of a string of length 'N'.
Your task is to return the maximum and minimum difference of the three strings for all the possible rotations of string a.
For Example:
If the value of 'N' is 2, 'A' is "ab", 'B' is "aa" and 'C' is "bb".
Then the answer for this input is
min = 2
max = 2
Because current difference is 1 + 1 = 2
After one rotation difference will be 1 + 1 = 2 Hence, the minimum and the maximum answer is 2.
*/

vector<int> similarStrings(int n, string a, string b, string c) {

}