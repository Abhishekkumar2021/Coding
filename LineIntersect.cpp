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

    // Orientaion of other vector wrt it
    int orientaion(const Vector &b){
        long long ans = cross(b);
        if(ans > 0) return 0;  // Anticlockwise
        if(ans == 0) return 1;  // Parallel
        return 2;  // Clockwise
    }
};

bool onSegment(Vector a, Vector b, Vector c){
    // This check if c lies between a and b
    return (
        c.x >= min(a.x, b.x) &&
        c.x <= max(a.x, b.x) &&
        c.y >= min(a.y, b.y) &&
        c.y <= max(a.y, b.y)
    );
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int testCases;
    cin>>testCases;
    for(int test = 0; test < testCases; test++){
        Vector a, b, c, d;
        a.read();
        b.read();
        c.read();
        d.read();

        // calculate point orientaions
        int o1 = (b - a).orientaion(c - a);
        int o2 = (b - a).orientaion(d - a);
        int o3 = (d - c).orientaion(a - c);
        int o4 = (d - c).orientaion(b - c);

        if(o1 != o2 && o3 != o4) cout << "YES\n";
        else if(
            (o1 == 1 && onSegment(a, b, c)) ||
            (o2 == 1 && onSegment(a, b, d)) ||
            (o3 == 1 && onSegment(c, d, a)) ||
            (o4 == 1 && onSegment(c, d, b)) 
        ) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}