/*
Given an array consisting of atmax three types of elements, sort it in linear time and constant space.
Example:
1.
Input: 1 2 0 2 1 0 1 2 0 0 0 1
Output: 0 0 0 0 0 0 1 1 1 1 2 2

2.
6 5 6 6 4 4 
Output: 4 4 5 6 6 6

3.
8 8 9 9 8
Output: 8 8 8 9 9

Approach:
1. Count the number of 0s, 1s and 2s.
2. Replace the elements with 0s, 1s and 2s.

Time Complexity: O(n)
Space Complexity: O(1)

Another Approach: Dutch National Flag Algorithm
1. Maintain three pointers low, mid and high.
2. low points to the first element of the array.
3. mid points to the first element of the array.
4. high points to the last element of the array.
5. If mid is 0, swap a[low] and a[mid] and increment low and mid.
6. If mid is 1, increment mid.
7. If mid is 2, swap a[mid] and a[high] and decrement high.
8. Repeat steps 5 to 7 until mid is greater than high.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int> &a) {
    int n = a.size();
    int low = 0;
    int mid = 0;
    int high = n - 1;
    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            low++;
            mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else {
            swap(a[mid], a[high]);
            high--;
        }
    }
}