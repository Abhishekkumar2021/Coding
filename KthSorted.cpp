#include<bits/stdc++.h>
using namespace std;

/*
a = [1, 2, 4]
b = [3, 5, 6]

k = 4

final = [1, 2, 3, 4, 5, 6]

left = 0, right = n
*/

int search(vector<int> &a, vector<int> &b, int k){
    int n = a.size();
    int m = b.size();
    if(n>m) return search(b, a, k);

    int left = 0, right = n;
    while(left <= right){
        int cntA = left + (right-left)/2;
        int cntB = k - cntA;

        int l1 = cntA == 0 ? INT_MIN : a[cntA-1]; 
        int l2 = cntB == 0 ? INT_MIN : b[cntB-1]; 
        int r1 = cntA == n ? INT_MAX : a[cntA]; 
        int r2 = cntB == m ? INT_MAX : b[cntB]; 

        if(l1 <= r2 and l2 <= r1){
            return max(l1, l2);
        }else if(l1 > r2) right = cntA - 1;
        else left  = cntA + 1;
    }
}
int main(){
    vector<int> a = {1, 2, 3, 5};
    vector<int> b = {4, 6, 7, 8};
    cout << search(a, b, 5) << endl;
}