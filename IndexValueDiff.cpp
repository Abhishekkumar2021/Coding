#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int min, max, minIndex, maxIndex;
    Node(){
        // Nothing
    }
    Node(int a, int b, int c, int d){
        min = a;
        max = b;
        minIndex = c;
        maxIndex = d;
    }
};

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int k, int d) {
        int n = nums.size();
        vector<Node> arr(n);
        for(int i=n-1; i>=0; i--){
            if(i == n-1){
                arr[i] = Node(nums[i], nums[i], n-1, n-1);
            }else{
                if(nums[i] < arr[i+1].min){
                    arr[i].min = nums[i];
                    arr[i].minIndex = i;
                }else{
                    arr[i].min = arr[i+1].min;
                    arr[i].minIndex = arr[i+1].minIndex;
                }

                if(nums[i] > arr[i+1].max){
                    arr[i].max = nums[i];
                    arr[i].maxIndex = i;
                }else{
                    arr[i].max = arr[i+1].max;
                    arr[i].maxIndex = arr[i+1].maxIndex;
                }
            }
        }
        for(int i=0; i<n-k; i++){
            Node q = arr[i+k];
            if(abs(q.min - nums[i]) >= d) return {i, q.minIndex};
            if(abs(q.max - nums[i]) >= d) return {i, q.maxIndex};
        }
        return {-1, -1};
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
    }
    return 0;
}
