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

long long segmentLattice(Vector a, Vector b){
    Vector ab = b - a;
    return __gcd(abs(ab.x), abs(ab.y)) + 1;
}

long long boundaryLattice(vector<Vector> &arr){
    long long ans = 0;
    int n = arr.size();
    for(int i = 1; i<=n; i++){
        ans += segmentLattice(arr[i-1], arr[i%n]) - 1;
    }
    return ans;
}

long long area(vector<Vector> &arr){
    long long ans = 0;
    int n = arr.size();
    for(int i=2; i<n; i++){
        Vector a = arr[i-1] - arr[0]; 
        Vector b = arr[i] - arr[0]; 
        ans += a.cross(b);
    }
    return abs(ans);
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<Vector> point(n);
    for(int i=0; i<n; i++) point[i].read();

    // Pick's Formulae
    // A = i + b/2 - 1
    long long boundary = boundaryLattice(point);
    long long A = area(point)/2;
    long long inside = A + 1 - boundary/2; 
    cout << inside << " " << boundary << "\n";
    return 0;
}
