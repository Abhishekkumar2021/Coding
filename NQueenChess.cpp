#include<bits/stdc++.h>
using namespace std;

bool possible(vector<vector<bool>> &vis, int row, int col, int n){
    // Vertical column
    for(int i=0; i<row; i++){
        if(vis[i][col] == true) return false;
    }

    // Horizontal
    for(int i=0; i<col; i++){
        if(vis[row][i] == true) return false;
    }

    // Diagonally
    int i = row - 1;
    int j = col - 1;
    while(i>=0 && j>=0){
        if(vis[i][j]) return false;
        i--, j--;
    }
    // Diagonally
    i = row - 1;
    j = col + 1;
    while(i>=0 && j<n){
        if(vis[i][j]) return false;
        i--, j++;
    }
    return true;
}

void place(int row, vector<vector<bool>> &vis, vector<vector<bool>> &reserved, int n, int &ans){
    if(row == n){
        ans++;
        return;
    }

    for(int i=0; i<n; i++){
        if(!reserved[row][i] && possible(vis, row, i, n)){
            vis[row][i] = true;
            place(row+1, vis, reserved, n, ans);
            vis[row][i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<bool>> vis(8, vector<bool>(8, false));
    vector<vector<bool>> reserved(8, vector<bool>(8, false));
    for(int i=0; i<8; i++){
        string s;
        cin >> s;
        for(int j=0; j<8; j++){
            if(s[j] == '*') reserved[i][j] = true;
        }
    }
    int ans = 0;
    place(0, vis, reserved, 8, ans);
    cout << ans << "\n";
    return 0;
}
