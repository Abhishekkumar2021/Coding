#include <bits/stdc++.h>
using namespace std;
// given a number N find out the nearest numbers to both side of N which have same number of set bits as N
void swap(int &x, int i, int j)
{
    if (((x >> i) & 1) != ((x >> j) & 1))
    {
        x ^= (1 << i) | (1 << j);
    }
}
vector<int> nearestNumbers(int n)
{
    // Write your code here
    // int count = __builtin_popcount(n);

    // int left = n-1;
    // int right = n+1;
    // while(__builtin_popcount(left) != count){
    //     left--;
    // }
    // while(__builtin_popcount(right) != count){
    //     right++;
    // }
    // vector<int> ans;
    // ans.push_back(left);
    // ans.push_back(right);
    // return ans;

    // Effecient Solution
    int i = 31;
    int j = 0;

    // Remove trailing 0's
    while (((n >> i) & 1) == 0)
    {
        i--;
    }

    // Remove leading 0's
    while (((n >> j) & 1) == 0)
    {
        j++;
    }

    int left = i;
    int right = j;

    // Now move i to the first unset bit
    while (((n >> i) & 1) == 1)
    {
        i--;
    }

    // Now move j to the first unset bit
    while (((n >> j) & 1) == 1)
    {
        j++;
    }

    int next = n;
    swap(next, right, j);

    int prev = n;
    swap(prev, left, i);

    return {next, prev};
}