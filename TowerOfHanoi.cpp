#include<bits/stdc++.h>
using namespace std;

void helper(int n, int src, int des){
    if(n == 1){
        cout << "Move disk " << n << " from rod " << src << " to rod " << des << endl;
        return;
    }
    int aux = 6 - src - des;
    helper(n-1, src, aux);
    cout << "Move disk " << n << " from rod " << src << " to rod " << des << endl;
    helper(n-1, aux, des);
}

void towerOfHanoi(int n){
    helper(n, 1, 3);
}

int main(){
    int n = 3;
    towerOfHanoi(n);
    return 0;
}