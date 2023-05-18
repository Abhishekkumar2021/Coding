/*
You are given an array 'ARR' of 'N' integers and two integers 'K' and 'M'.
You need to return true if the given array can be divided into pairs such that the sum of
every pair gives remainder 'M' when divided by 'K'. Otherwise, you need to return false.
For example:
If the given array is [2, 1, 5, 7] and K =
9 and M = 3. Then you need to
return true because we can divide the array into two pairs, i.e (2, 1)
and (5, 7) whose sums are 3 and 12, which when divided by 9 gives
remainder 3, thus it is possible to divide the given
Note:
Every element of the array should contribute to only
the array is [3, 0] and K =
2 and M = 1, then you
false, as element 3 will make a pair with any one of
array into pairs.
one pair, i.e if
need to return
the 0.

Hints:
1. You can use the concept of remainder to solve this problem.
2. You can use the concept of hashing to solve this problem.
3. You can use the concept of sorting to solve this problem.

Approach:
1.
2.
3.
4.
5.
6.
7.
1.If the length of the given array 'ARR' is odd, return false as the odd
length array cannot be divided into pairs.
2. Use a hashmap to store the frequencies of all the remainders.
3. Traverse the array and calculate ARR[i] % K and store its frequency
into the map.
4. Traverse all the keys of the map and check :
5. If the current key of the map is half of the 'M' then there must be an
even occurrence of those remainder so that it can form pairs. Thus,
check its frequency if it is odd then return false.
6. Else, for the current element 'X' check the frequency of (M - X), if
frequencies of both elements are not equal then return false.
If all the keys are traversed then return true.
*/

#include<bits/stdc++.h>
using namespace std;

bool isValidPair(vector<int> &arr, int n, int k, int m)
{
    // Write your code here.
    if(n%2!=0)
        return false;
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]%k]++;
    }
    for(auto &p : mp){
        int x = p.first;
        int comp = (m - x + k)%k;
        if(x == comp){
            if(p.second%2!=0)
                return false;
        }
        else{
            if(mp[comp]!=p.second)
                return false;
        }
    }
    return true;
}
