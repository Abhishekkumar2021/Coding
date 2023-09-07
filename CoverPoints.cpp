#include<bits/stdc++.h>
using namespace std;

int coverPoints(vector<int> &x, vector<int> &y) {
    int ans = 0;
    for(int i = 1; i < x.size(); i++) {
        ans += max(abs(x[i] - x[i - 1]), abs(y[i] - y[i - 1]));
    }
    return ans;
}