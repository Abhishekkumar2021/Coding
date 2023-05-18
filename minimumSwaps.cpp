/*
During Endgame Natasha(Black Widow) sacrificed her life for the soul stone.
Hulk wants to bring Natasha back. So, he came to Goku for help. Goku told him he will
help Hulk if he can solve the task given by him. Hulk accepts the challenge of Goku.
Goku gave Hulk a list of 'N' numbers and a number 'K'. The task is to rearrange the
elements of the list such that all elements less than or equal to 'K' become adjacent to
each other. Hulk can only swap any two elements of the array/list multiple times. Goku
wants Hulk to do the task using the minimum number of swaps.
As Hulk is not good at maths so he called you to solve the task given by Goku to save
Natasha.The fate of Natasha lies in your hand.

Approach:
1. Sort the array and store the index of the elements in a map.
2. Now, traverse the array and check if the element is greater than K or not.
3. If the element is greater than K then swap it with the element at the index stored
in the map.
4. Increment the count of swaps.
5. Repeat the above steps until the array is sorted.
6. Return the count of swaps.
*/

#include <bits/stdc++.h>
using namespace std;

int minimumSwaps(vector<int> arr, int n, int k) {
    int count = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[arr[i]] = i;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        if (arr[i] > k) {
            swap(arr[i], arr[m[k]]);
            count++;
        }
    }
    return count;
}