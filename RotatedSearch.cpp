/*
Given a sorted rotated array the task is to find index of a key in O(log n) time. If the key is not present in the array, then return -1.

Examples:
Input: arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}, key = 3
Output: 8

Input: arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}, key = 30
Output: -1

Approach:
1. Find the pivot element.
2. If the pivot element is the key, return the pivot element.
3. If the pivot element is greater than the key, search in the left subarray.
4. If the pivot element is smaller than the key, search in the right subarray.

Time Complexity: O(log n)
*/

#include<bits/stdc++.h>
using namespace std;

int findPivot(vector<int> &a) {
    int n = a.size();
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (mid < high && a[mid] > a[mid + 1]) {
            return mid;
        }
        if (mid > low && a[mid] < a[mid - 1]) {
            return mid - 1;
        }
        if (a[low] >= a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int binarySearch(vector<int> &a, int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) {
            return mid;
        }
        if (a[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int rotatedSearch(vector<int> &a, int key) {
    int n = a.size();
    int pivot = findPivot(a);
    if (pivot == -1) {
        return binarySearch(a, 0, n - 1, key);
    }
    if (a[pivot] == key) {
        return pivot;
    }
    if (a[0] <= key) {
        return binarySearch(a, 0, pivot - 1, key);
    }
    return binarySearch(a, pivot + 1, n - 1, key);
}