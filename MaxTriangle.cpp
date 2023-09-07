#include <bits/stdc++.h>
using namespace std;

int index(char ch)
{
    return ch == 'r' ? 0 : ch == 'g' ? 1
                                     : 2;
}

class value
{
public:
    int min;
    int max;
    value()
    {
        min = INT_MAX;
        max = INT_MIN;
    }
};

int maxArea(vector<string> matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    vector<value> minMaxRow[col];
    for (int i = 0; i<col; i++)
        minMaxRow[i].resize(3);
    vector<value> minMaxCol(3);

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            int idx = index(matrix[i][j]);

            // Columns
            minMaxCol[idx].min = min(minMaxCol[idx].min, j);
            minMaxCol[idx].max = max(minMaxCol[idx].max, j);

            // Rows
            minMaxRow[j][idx].min = min(minMaxRow[j][idx].min, i);
            minMaxRow[j][idx].max = max(minMaxRow[j][idx].max, i);
        }
    }

    double ans = 0;
    for(int j=0; j<col; j++){
        // R & B as base and G as other vertices
        if(minMaxRow[j][0].min != INT_MAX && minMaxRow[j][2].min != INT_MAX){
            double base = max(abs(minMaxRow[j][0].max - minMaxRow[j][2].min),abs(minMaxRow[j][2].max - minMaxRow[j][0].min))+1;
            double height = max(abs(minMaxCol[1].max-j), abs(j-minMaxCol[1].min)) + 1;
            ans = max(ans, 0.5*base*height);
        }
        // R & G as base and B as other vertices
        if(minMaxRow[j][0].min != INT_MAX && minMaxRow[j][1].min != INT_MAX){
            double base = max(abs(minMaxRow[j][0].max - minMaxRow[j][1].min),abs(minMaxRow[j][1].max - minMaxRow[j][0].min))+1;
            double height = max(abs(minMaxCol[2].max-j), abs(j-minMaxCol[2].min)) + 1;
            ans = max(ans, 0.5*base*height);
        }
        // B & G as base and R as other vertices
        if(minMaxRow[j][2].min != INT_MAX && minMaxRow[j][1].min != INT_MAX){
            double base = max(abs(minMaxRow[j][1].max - minMaxRow[j][2].min),abs(minMaxRow[j][2].max - minMaxRow[j][1].min))+1;
            double height = max(abs(minMaxCol[0].max-j), abs(j-minMaxCol[0].min)) + 1;
            ans = max(ans, 0.5*base*height);
        }
        
    }
    return ceil(ans);
}
int solve(vector<string> &A) {
    return maxArea(A);
}