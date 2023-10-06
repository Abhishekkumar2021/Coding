#include<bits/stdc++.h>
using namespace std;

class Vector{
    public:
    long long x;
    long long y;

    Vector(){
        x = 0;
        y = 0;
    }
    Vector(long long x, long long y){
        this->x = x;
        this->y = y;
    }
    
    // Read
    void read(){
        cin >> x >> y;
    }

    // Vector Addition
    Vector operator +(const Vector &b){
        return Vector(x + b.x, y+b.y);
    }

    // Vector Substraction
    Vector operator -(const Vector &b){
        return Vector(x - b.x, y - b.y);
    }

    // Dot product
    long long dot(const Vector &b){
        return (x*b.x + y*b.y);
    }

    // Cross product
    long long cross(const Vector &b){
        return (x*b.y - b.x*y);
    }
};

class Solution{
    int n;
    vector<Vector> arr;
    public:
    Solution(){
        cin >> n;
        arr.resize(n);
        for(int i=0; i<n; i++){
            arr[i].read();
        }
    }

    long long area(){
        long long ans = 0;
        for(int i=2; i<n; i++){
            Vector a = arr[i-1] - arr[0]; 
            Vector b = arr[i] - arr[0]; 
            ans += a.cross(b);
        }
        return abs(ans);
    }
};

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    Solution s;
    cout << s.area() << endl;
    return 0;
}
