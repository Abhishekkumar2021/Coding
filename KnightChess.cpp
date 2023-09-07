#include<bits/stdc++.h>
using namespace std;

int knight(int n, int m, int sr, int sc, int er, int ec) {
    vector<vector<int>> g(n+1, vector<int>(m+1, 0));
    int ans = 0;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    g[sr][sc] = 1;
    // 8 possibilities
    vector<int> dr = {2, 2, -2, -2, 1, 1, -1, -1};
    vector<int> dc = {1, -1, 1, -1, 2, -2, 2, -2};
    while(!q.empty()){
        int size = q.size();
        while(size--){
            auto p = q.front();
            q.pop();
            if(p.first == er && p.second == ec) return ans;
            for(int i=0; i<8; i++){
                int nr = p.first + dr[i];
                int nc = p.second + dc[i];

                // invalid
                if(nr < 1 || nr > n || nc < 1 || nc > m || g[nr][nc]==1) continue;

                q.push({nr, nc});
                g[nr][nc] = 1;
            }  
        }
        ans++;
    }
    return -1;
}

int main(){
    cout << knight(8, 8, 1, 1, 8, 8) << endl;
}