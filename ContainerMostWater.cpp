/*
Given a sequence of 'N' space-separated non-negative integers
A[1],A[2],A[3].........A[i].......A[n]. Where each number of the sequence represents the height of the line drawn at point 'i'. Hence on the cartesian plane, each line is drawn from coordinate ('i',0) to coordinate ('i', 'A[i]'), here 'i' ranges from 1 to 'N'. Find two lines, which, together with the x-axis forms a container, such that the container contains the most area of water.
Note:
1. You can not slant the container i.e. the height of the water is equal to the minimum height of the two lines which define the container.
2. Do not print anything, you just need to return the area of the container with maximum water.
*/

#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    // Write your code here.
    int n = height.size();
    int i = 0, j = n-1;
    int maxArea = 0;
    while(i < j){
        int area = min(height[i], height[j]) * (j-i);
        maxArea = max(maxArea, area);
        if(height[i] < height[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return maxArea;
}