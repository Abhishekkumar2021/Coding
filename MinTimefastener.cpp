#include<bits/stdc++.h>
using namespace std;

// Binary Search : Minimize the maximum time
bool possible(int t, vector<int> &speed, int boxes){
    int count = 0;
    int n = speed.size();
    for(int i=0; i<n; i++){
        // Determinant condition
        if(4*t < 3*speed[i]) return false;
        double x1 = (1 - sqrt(4.0*t/speed[i] - 3))/2;
        double x2 = (1 + sqrt(4.0*t/speed[i] - 3))/2;
        double x = max(x1, x2);
        count += (int)x;

        if(count >= boxes) return true;
    }
    return false;
}

int minTime(vector<int> &speed, int boxes, int trucks){
    long long left = 1, right = 1e14;
    long long ans = -1;
    while(left <= right){
        long long mid = left + (right-left)/2;
        if(possible(mid, speed, boxes)){
            ans = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return ans;
}


int main(){
    int boxes, trucks;
    cin>>boxes>>trucks;
    vector<int> speed(trucks);
    for(int i=0; i<trucks; i++) cin>>speed[i];
    int ans = minTime(speed, boxes, trucks);
    cout << ans << endl;
}