#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &arr, int n){
    int count = 0;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
            count++;
    }
    if(count>1)
        return false;
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        // we have to check that if it is possible to sort the array in non decreasing array by modifying at most one element only
        if(isPossible(arr, n))
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
}