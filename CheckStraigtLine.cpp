#include<bits/stdc++.h>
using namespace std;

bool checkStraightLine(vector<vector<int>>& coordinates) {
    vector<int> v1 = coordinates[0];
    vector<int> v2 = coordinates[1];
    int x1 = v1[0], y1 = v1[1], x2 = v2[0], y2 = v2[1];
    for(int i=2;i<coordinates.size();i++){
        vector<int> v = coordinates[i];
        int x = v[0], y = v[1];
        if((y2-y1)*(x-x1)!=(y-y1)*(x2-x1)) return false;
    }
    return true;
}