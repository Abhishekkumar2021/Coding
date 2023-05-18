#include<bits/stdc++.h>
using namespace std;

int main(){
    int testCases;
    cin>>testCases;
    for(int i=1; i<=testCases; i++){
        int n;
        cin>>n;
        int count = 0;
        while(true){
            if(n - 26*count < 0){
                break;
            }
            n -= 26*count;
            count++;
        }
        int rem = n%count;
        int quo = n/count;
        cout << "Case #" << i << ": " << (char)('A' + quo + rem ? 1 : 0) <<endl;
    }
}