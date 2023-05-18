#include<bits/stdc++.h>
using namespace std;

void countingSort(vector<int> &arr){
    // Find the max element in the array
    int max = *max_element(arr.begin(), arr.end());

    // Create a count array of size max+1
    vector<int> count(max+1, 0);

    // Count the occurence of each element
    for(int i=0; i<arr.size(); i++){
        count[arr[i]]++;
    }

    // Update the count array to store the sum of previous counts
    for(int i=1; i<count.size(); i++){
        count[i] += count[i-1];
    }

    // Create a temp array to store the sorted array
    vector<int> temp(arr.size(), 0);

    // Traverse the array from the end (we are traversing from the end because we want to maintain the order of the elements)
    for(int i=arr.size()-1; i>=0; i--){
        temp[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted array to the original array
    for(int i=0; i<arr.size(); i++){
        arr[i] = temp[i];
    }
}

int main(){
    vector<int> arr = {1, 4, 1, 2, 7, 5, 2};
    countingSort(arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}