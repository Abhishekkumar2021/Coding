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

    // Distance of other vector from this
    double distance(const Vector &b){
        return sqrt((x - b.x)*(x - b.x) + (y - b.y)*(y - b.y));
    }
};

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<Vector> arr(n);
    for(int i=0; i<n; i++) arr[i].read();

    // // Graham Scan algorithm
    Vector pivot(INT_MIN, INT_MAX);
    for(auto &p: arr){
        if(p.y < pivot.y) pivot = p;
        else if(p.y == pivot.y && p.x < pivot.x) pivot = p; 
    }
    
    sort(arr.begin(), arr.end(), [&](Vector &a, Vector &b){
        int x = (a - pivot).orientaion(b - pivot);
        if(x == 0) return true;
        else if(x == 1 && pivot.distance(a) < pivot.distance(b)) return true;
        return false;
    });

    // for(auto &p: arr) cout << p.x << " " << p.y << endl;

    // Make a stack that stores the indexes of the points in the convex hull
    stack<int> st;
    st.push(0);
    st.push(1);

    int idx = 2;
    while(idx < n){
        int top = st.top();
        st.pop();
        int next = st.top();
        Vector a = arr[top] - arr[next];
        Vector b = arr[idx] - arr[next];
        // If orientaion of the current point is clockwise then pop the element otherwise push and go on next point
        if(a.orientaion(b) <= 1){
            st.push(top);
            st.push(idx);
            idx++;
        }
    }

    vector<Vector> ans;
    // Print the points in the convex hull
    
    while(!st.empty()){
        Vector p = arr[st.top()];
        ans.push_back(p);
        st.pop();
    }
    cout << ans.size() << "\n";
    for(auto &p: ans) cout << p.x << " " << p.y << endl;
    return 0;
}