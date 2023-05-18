#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    // Write your code here.
    int n = height.size();
    int maxArea = 0;

    // Using stack
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!s.empty() && height[s.top()] > height[i])
        {
            int top = s.top();
            s.pop();
            int area = height[top] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, area);
        }
        s.push(i);
    }
    
}