/*
You are given three strings "A", "B" and "C". Your task is to
check whether "C" is formed by an interleaving of A and
B. C is said to be interleaving "A" and "B", if the length of
"C" is equal to the sum of the length of A and length of B,
all the characters of "A" and "B" are present in "C", and
the order of all these characters remains the same in all
three strings.
For Example:
If A = "aab",
B — "abc",
C — "aaabbc"
Here C is an interleaving string of A and B.
Because C contains all the characters of A
and B and the order of all these characters
is also the same in all three strings.

Approach:
1. If the length of C is not equal to the sum of the length of A and B, then return false.
2. If the length of C is equal to the sum of the length of A and B, then check whether all the characters of A and B are present in C or not.
3. If all the characters of A and B are present in C, then check whether the order of all these characters remains the same in all three strings or not.
4. If the order of all these characters remains the same in all three strings, then return true.
5. Else return false.

Time Complexity: O(N)
Space Complexity: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

bool isInterleave(string a, string b, string c){
	//Your code goes here
	int x = a.size();
	int y = b.size();
	int z = c.size();
	if(x + y != z) return false;

    bool dp[x+1][y+1];
    memset(dp, false, sizeof(dp));

    for(int i = 0; i <= x; i++){
    	for(int j = 0; j <= y; j++){
    		if(i == 0 && j == 0) dp[i][j] = true;
    		else if(i == 0){
    			if(b[j-1] == c[j-1]) dp[i][j] = dp[i][j-1];
    		}
    		else if(j == 0){
    			if(a[i-1] == c[i-1]) dp[i][j] = dp[i-1][j];
    		}
    		else if(a[i-1] == c[i+j-1] && b[j-1] != c[i+j-1]) dp[i][j] = dp[i-1][j];
    		else if(a[i-1] != c[i+j-1] && b[j-1] == c[i+j-1]) dp[i][j] = dp[i][j-1];
    		else if(a[i-1] == c[i+j-1] && b[j-1] == c[i+j-1]) dp[i][j] = dp[i-1][j] || dp[i][j-1];
    	}
    }
    return dp[x][y];
}