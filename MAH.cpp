#include<bits/stdc++.h>
using namespace std;

vector<int> NSE(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i=n-1; i>=0; i--){
        while(!s.empty() && arr[i] <= arr[s.top()]){
            s.pop();
        }
        if(s.empty()){
            ans[i] = n;
        }
        else{
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}

vector<int> PSE(vector<int> &arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i=0; i<n; i++){
        while(!s.empty() && arr[i] <= arr[s.top()]){
            s.pop();
        }
        if(s.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }
        s.push(i);
    }
    return ans;
}

int maxArea(vector<int> &arr){
    int n = arr.size();
    vector<int> nse = NSE(arr);
    vector<int> pse = PSE(arr);
    int maxArea = 0;
    for(int i=0; i<n; i++){
        int width = nse[i] - pse[i] - 1;
        int area = width * arr[i];
        maxArea = max(maxArea, area);
    }
    return maxArea;
}