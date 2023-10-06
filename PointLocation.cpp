#include<bits/stdc++.h>
using namespace std;

class Solution{
    int x1, y1, x2, y2, x3, y3; 
    public:
    void input(){
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    }

    // Equation of line
    double crossProduct(){
        // Vector a = (x2-x1)i + (y2-y1)j;
        // Vector b = (x3-x1)i + (y3-y1)j;

        // Now if a x b is negative then that means point p3 is right  to point p1 and p2
        return (x2-x1)*1.0*(y3-y1) - (y2-y1)*1.0*(x3-x1);
    }
};

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int testCases;
    cin>>testCases;
    for(int test = 0; test < testCases; test++){
        Solution s;
        s.input();
        double ans = s.crossProduct();
        if(ans == 0) cout << "TOUCH" << endl;
        else if(ans > 0) cout << "LEFT" << endl;
        else cout << "RIGHT" << endl;

    }
    return 0;
}
