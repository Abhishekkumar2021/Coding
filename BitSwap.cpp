#include<bits/stdc++.h>
using namespace std;
void swap(int &x, int i, int j){
    if(((x>>i)&1) != ((x>>j)&1)){
        x ^= (1<<i) | (1<<j);
    }
}
int main(){
    int x = 10;
    swap(x, 1, 3);
}