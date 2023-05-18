#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int i = 0, j = arr.size() - 1;

    while(i < j){
        if(arr[i] + arr[j] == s){
            if(arr[i] == arr[j]){
                int cnt = j - i + 1;
                // number of pairs = nC2 = n * (n - 1) / 2
                for(int k = 0; k < cnt * (cnt - 1) / 2; k++){
                    ans.push_back({arr[i], arr[j]});
                }
                break;
            }
            else{
                int cnt_i = 1, cnt_j = 1;
                while(i + 1 < j && arr[i] == arr[i + 1]){
                    cnt_i++;
                    i++;
                }
                while(j - 1 > i && arr[j] == arr[j - 1]){
                    cnt_j++;
                    j--;
                }
                int cnt = cnt_i * cnt_j;
                for(int k = 0; k < cnt; k++){
                    ans.push_back({arr[i], arr[j]});
                }
            }   
            i++;
            j--;
        }
        else if(arr[i] + arr[j] < s){
            i++;
        }
        else{
            j--;
        }
    }
    return ans;
}


// 83 => 