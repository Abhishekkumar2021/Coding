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

class Solution{
    int n, m;
    vector<Vector> arr;
    vector<Vector> point;
    public:
    Solution(){
        cin >> n >> m;
        arr.resize(n);
        point.resize(m);
        for(int i=0; i<n; i++){
            arr[i].read();
        }
        for(int i=0; i<m; i++){
            point[i].read();
        }
    }

    bool onSegment(Vector a, Vector b, Vector c){
        // This check if c lies between a and b
        return (
            c.x >= min(a.x, b.x) &&
            c.x <= max(a.x, b.x) &&
            c.y >= min(a.y, b.y) &&
            c.y <= max(a.y, b.y)
        );
    }

    bool intersect(Vector a, Vector b, Vector c, Vector d){
        int o1 = (b-a).orientaion(c-a);
        int o2 = (b-a).orientaion(d-a);
        int o3 = (d-c).orientaion(b-c);
        int o4 = (d-c).orientaion(a-c);

        return o1 != o2 && o3 != o4;
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

    bool lieOnSegment(Vector a, Vector b, Vector p){
        return (b - a).orientaion(p - a) == 1 && onSegment(a, b, p);
    }

    int pointLies(vector<Vector> &arr, Vector &p){
        Vector inf(INT_MAX, INT_MIN);
        bool boundary = false;
        long long cnt = 0;
        for(int i=1; i<=n; i++){
            if(lieOnSegment(arr[i-1], arr[i%n], p)){
                boundary = true;
                break;
            }
        }
        if(boundary){
            return 0;
        }
        for(int i=1; i<=n; i++){
            if(intersect(arr[i-1], arr[i%n], p, inf)) cnt++;
        }
        if(cnt%2 == 0) return 1;
        else return -1;
    }

    void solve(){
        /* Area method works well when the polygon is convex but on concave polygon it will going to give wrong answer
        long long original = area();
        for(auto &p: point){
            long long ans = 0;
            bool boundary = false;
            for(int i=1; i<=n; i++){
                Vector a = arr[i-1] - p; 
                Vector b = arr[i%n] - p; 
                long long x = a.cross(b);
                if(x == 0){
                    boundary = true;
                    break;
                }
                ans += abs(x);
            }
            if(boundary) cout << "BOUNDARY\n";
            else if(ans == original) cout << "INSIDE\n";
            else cout << "OUTSIDE\n";
        }
        */

        // Number of intersection between polygon line segments and (p - infinity) segment
        for(auto &p: point){
            int x = pointLies(arr, p);
            if(x == 0){
                cout << "BOUNDARY\n";
                continue;
            }
            else if(x == 1) cout << "OUTSIDE\n";
            else cout << "INSIDE\n";
        }
        
    }
};

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}
