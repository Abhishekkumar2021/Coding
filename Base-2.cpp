#include<bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> &A, vector<int> &B)
{
    long long x = 0, y = 0;
    int n = A.size(), m = B.size();
    for(int i=0; i<n; i++){
        x += A[i] * 1LL * pow(-2, i);
    }
    for(int i=0; i<m; i++){
        y += B[i] * 1LL * pow(-2, i);
    }
    long long z = x + y;
    vector<int> res;
    while(z != 0){
        int rem = z % -2;
        z /= -2;
        if(rem < 0){
            rem += 2;
            z += 1;
        }
        res.push_back(rem);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> a = {0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1};
    vector<int> b = {0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1};
    vector<int> res = solution(a, b);
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    return 0;
}
