/*
Problem Statement
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

Approach:
1. We will use the slope of the line to find the maximum number of points that lie on the same line.
2. We will use a map to store the slope of the line and the number of points that lie on that line.
3. We will iterate over the points and find the slope of the line between the current point and all the other points.
4. We will store the slope of the line in the map and increment the count of the slope by 1.
5. We will find the maximum count of the slope and return it as the answer.
*/

#include<bits/stdc++.h>
using namespace std;

int maxPointsOnLine(vector<vector<int>> &points, int n) {
	// Write your code here.
    int ans = INT_MIN;
    for(int i = 0; i < n; i++){
        map<double, int> slope;
        int same = 0;
        int vertical = 0;
        int maxPoints = 0;
        for(int j = i + 1; j < n; j++){
            if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                same++;
            }
            else if(points[i][0] == points[j][0]){
                vertical++;
            }
            else{
                double slopeOfLine = (double)(points[j][1] - points[i][1]) / (double)(points[j][0] - points[i][0]);
                slope[slopeOfLine]++;
                maxPoints = max(maxPoints, slope[slopeOfLine]);
            }
        }
        maxPoints = max(maxPoints, vertical);
        ans = max(ans, maxPoints + same + 1);
    }
    return ans;
}